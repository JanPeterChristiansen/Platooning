void bluetooth::_beginSerial() { // starts the correct Serial depending on the specified pins for RX/TX
  // Not used, BT is always Serial 3 !!!
  switch (bluetooth::_TX) { 
    case (19):
      Serial1.begin(38400);
        break;
    case (17):
      Serial2.begin(38400);
      break;
    case (15):
      Serial3.begin(38400);
      break;
  }
}

void bluetooth::receive() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

  while (Serial3.available() > 0 && bluetooth::_newData == false) {
    rc = Serial3.read();
    if (recvInProgress == true) {
      if (rc != endMarker) {
        bluetooth::_receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= bluetooth::_numChars) {
          ndx = bluetooth::_numChars - 1;
        }
      }
      else {
        bluetooth::_receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        bluetooth::_newData = true;
      }
    }
    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}

void bluetooth::_parseData() {
  // split the data into its parts
  char * strtokIndx; // this is used by strtok() as an index

  strtokIndx = strtok(bluetooth::_receivedChars, ","); // this continues where the previous call left off
  bluetooth::_intFromPC = atoi(strtokIndx);     // convert this part to an integer
}

void bluetooth::handleNewData() { //Triggers when a signal is recived
  if (bluetooth::_newData == true) {
    bluetooth::_parseData();
    bluetooth::_decideReceivedData();
    bluetooth::_newData = false;
  }
}

void bluetooth::_decideReceivedData() {  //Decides what to to with the recived data
  if (bluetooth::_intFromPC >= 0 && bluetooth::_intFromPC <= 100) {
    bluetooth::_motorSpeed = bluetooth::_intFromPC;
  }
  else {
    switch (bluetooth::_intFromPC) {
      case 101: //Drive right
        // turn = 'R';
        break;
      case 102: //Drive left
        // turn = 'L';
        break;
      case 103: //Platooning ON
        // platooning = true;
        break;
      case 104: //Platooning OFF
        // platooning = false;
        break;
      case 105: //Drive straight
        // turn = 'S';
        break;
      case 106: //Forwards gear
        // direction = 'F';
        break;
      case 107: //Reverse gear
        // direction = 'R';
        break;
    }
  }
}

void bluetooth::getMotorSpeed() {
  return bluetooth::_motorSpeed;
}
