#ifndef Swarm_h
#define Swarm_h

#include <Arduino.h>
#include <SoftwareSerial.h>

enum Message {
    MESSAGE_NONE = 0
}

class Swarm {
public:
    void begin(int rx, int tx);
    void send(Message msg, byte client = 255);
    Message recv();

private:
    SoftwareSerial mSerial;
};

#endif /* Swarm_h */