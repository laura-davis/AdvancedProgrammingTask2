#pragma once
#include "Comms.h"

class Client : public Comms {
public:
    Client();
    void ConnectSocket();
    string SendMessage() override;
    void ReceiveMessage(char* buffer, int size) override;
    void StartChat() override;
};