#pragma once

#include "Comms.h"

class Client : public Comms {
private:
    string SendMessage() override;

    void ReceiveMessage(char *buf, int size) override;

public:
    Client() = default;

    void OpenSocket() override;

    void ConnectSocket();

    void StartChat() override;
};