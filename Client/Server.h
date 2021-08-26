#pragma once
#include "Comms.h"

class Server : public Comms {
private:
    int clientSock;
    sockaddr_in client;
    socklen_t clientSockLength;
//    string ip = "127.0.0.1";
    std::string SendMessage() override;
    void ReceiveMessage(char* buf, int size) override;
public:
    Server()= default;
    void OpenSocket() override;
    void BindToSocket();
    void ListenToSocket();
    void AcceptSocket();
    void StartChat() override;
};
