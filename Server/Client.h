#pragma once
#include "Comms.h"

class Client : public Comms {
public:
    Client();
    void ConnectSocket();
    string GetUserInput() override;
    string SendMessage() override; // Override virtual method in Comms class
    void ReceiveMessage(char* buf, int size) override; // Override virtual method in Comms class
    void StartChat() override; // Override virtual method in Comms class
};