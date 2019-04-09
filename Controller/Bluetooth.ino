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
  if (_intFromPC >= 0 && _intFromPC <= 100) { // speed
    if (_reverse) { // reverse
      _speed = -_intFromPC;
    }
    else { // forward
      _speed = _intFromPC;
    }
  }
  else if (_intFromPC >= 900 && _intFromPC <= 1100) {
    // left to right (turn value)
    _turn = map(_intFromPC, 900, 1100, -100, 100);
  }
  else {
    switch (_intFromPC) {
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
        _reverse = false;
        break;
      case 107: //Reverse gear
        _reverse = true;
        break;
    }
  }
}

int bluetooth::getSpeed() {
  return _speed;
}

int bluetooth::getTurn() {
  return _turn;
}
