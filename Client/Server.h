#pragma once
#include "Comms.h"
#include <arpa/inet.h>

class Server : public Comms {
protected:
    int clientSocket{};
public:
    Server();
    string SendMessage() override;
    void ReceiveMessage(char *buf, int size) override;
    void BindSocket();
    void ListenSocket();
    void AcceptSocket();
    void StartChat() override;
};