void bluetooth::beginSerial() { // starts the correct Serial depending on the specified pins for RX/TX
  // Not used, BT is always Serial 3 !!!
  switch (TX) {
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

  while (Serial3.available() > 0 && newData == false) {
    rc = Serial3.read();
    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      }
      else {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }
    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}

void bluetooth::parseData() {
  // split the data into its parts
  char * strtokIndx; // this is used by strtok() as an index

  strtokIndx = strtok(receivedChars, ","); // this continues where the previous call left off
  intFromPC = atoi(strtokIndx);     // convert this part to an integer
}

void bluetooth::handleNewData() { //Triggers when a signal is recived
  if (newData == true) {
    parseData();
    decideReceivedData();
    newData = false;
  }
}

void bluetooth::decideReceivedData() {  //Decides what to to with the recived data
  if (intFromPC >= 0 && intFromPC <= 100) { // speed
    if (reverse) { // reverse
      speed = -intFromPC;
    }
    else { // forward
      speed = intFromPC;
    }
  }
  else if (intFromPC >= 900 && intFromPC <= 1100) {
    // left to right (turn value)
    turn = map(intFromPC, 900, 1100, -100, 100);
  }
  else {
    switch (intFromPC) {
      /*
        case 101: //Drive right
        // turn = 'R';
        break;
        case 102: //Drive left
        // turn = 'L';
        break;
        case 105: //Drive straight
        // turn = 'S';
        break;
      */
      case 103: //Platooning ON
        digitalWrite(13, HIGH);
        break;
      case 104: //Platooning OFF
        digitalWrite(13,LOW);
        break;
      case 106: //Forwards gear
        reverse = false;
        break;
      case 107: //Reverse gear
        reverse = true;
        break;
    }
  }
}

int bluetooth::getSpeed() {
  return speed;
}

int bluetooth::getTurn() {
  return turn;
}
