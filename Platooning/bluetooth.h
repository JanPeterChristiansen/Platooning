#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "Arduino.h"

class bluetooth { // object that handles communication with mobile app via bluetooth
  public:
    bluetooth(bool platooning = false, int RX = 15, int TX = 14);
    void receive();
    void handleNewData();
    int getSpeed();
    int getTurn();
    bool getPlatooning();

  private:
    int RX;
    int TX;
    const static byte numChars = 32;
    char receivedChars[numChars];
    bool newData = false;
    int intFromPC = 0;
    int speed = 0;
    int turn = 0;
    bool reverse = false;
    bool platooning = false;

    void decideReceivedData();
    void parseData();
    void beginSerial();

};

#endif
