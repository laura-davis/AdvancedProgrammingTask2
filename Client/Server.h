#pragma once
#include "Comms.h"
#include "Exception.h"

class Server : public Comms {
private:
    int listening;
    int clientSocket;
    string SendMessage() override;
    void ReceiveMessage(char* buf) override;
public:
    Server()= default;
    void ListenToSocket();
    void BindToSocket();
    void AcceptSocket();
    void StartChat() override;
};
