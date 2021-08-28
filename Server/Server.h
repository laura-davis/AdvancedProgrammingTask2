#pragma once
#include "Comms.h"
#include <arpa/inet.h>

class Server : public Comms {
protected:
    int server{}; // Integer variable for the Server and its various calls
public:
    Server();
    string SendMessage() override; // Override virtual method in Comms class
    void ReceiveMessage(char *buffer, int size) override; // Override virtual method in Comms class
    void BindSocket();
    void ListenSocket();
    void AcceptSocket();
    string GetUserInput() override;
    void StartChat() override; // Override virtual method in Comms class
};