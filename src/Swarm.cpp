#include "Swarm.hpp"

void Swarm::begin(int rx, int tx) {
    mSerial.begin(rx, tx);
}

void Swarm::send(Message msg, byte client) {
    mSerial.write(192);
    mSerial.write(168);
    mSerial.write(1);
    mSerial.write(client);
    mSerial.write(msg);
}

Message Swarm::recv() {
    if (mSerial.available() < 5) {
        return MESSAGE_NONE;
    }

    byte buffer[5];
    for (int i = 0; i < 5; i++) {
        buffer[i] = mSerial.read();
    }

    return (Message) buffer[4];
}