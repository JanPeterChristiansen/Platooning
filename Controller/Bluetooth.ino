void bluetooth::beginSerial() { // starts the correct Serial depending on the specified pins for RX/TX
  switch (bluetooth::_TX) {
    case (0):
      Serial.begin(38400);
      break;
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
