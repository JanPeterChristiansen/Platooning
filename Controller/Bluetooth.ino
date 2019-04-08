void bluetooth::_beginSerial() { // starts the correct Serial depending on the specified pins for RX/TX
  // Not used, BT is always Serial 3 !!!
  switch (_TX) {
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

  while (Serial3.available() > 0 && _newData == false) {
    rc = Serial3.read();
    if (recvInProgress == true) {
      if (rc != endMarker) {
        _receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= _numChars) {
          ndx = _numChars - 1;
        }
      }
      else {
        _receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        _newData = true;
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

  strtokIndx = strtok(_receivedChars, ","); // this continues where the previous call left off
  _intFromPC = atoi(strtokIndx);     // convert this part to an integer
}

void bluetooth::handleNewData() { //Triggers when a signal is recived
  if (_newData == true) {
    _parseData();
    _decideReceivedData();
    _newData = false;
  }
}

void bluetooth::_decideReceivedData() {  //Decides what to to with the recived data
  if (_intFromPC >= 0 && _intFromPC <= 100) {
    _speed = _intFromPC;
  }
  else {
    switch (_intFromPC) {
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

int bluetooth::getSpeed() {
  return _speed;
}
