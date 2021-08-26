// TODO - add notes everywhere
// TODO - complete readme file

#pragma once

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include "Exception.h"

using namespace std;

class Comms {
protected:
    int ERROR = -1;
    int BUF_SIZE = 200;
    int port = 54000;
    int socketRef{};
    struct sockaddr_in server_addr{};
    std::string GetUserInput();
    virtual std::string SendMessage() = 0;
    virtual void ReceiveMessage(char *buf, int size) = 0;
    static void PrintError(const string &error);

public:
    Comms() = default;
    virtual void OpenSocket() = 0;
    void CloseSocket() const;
    virtual void StartChat() = 0;
    static bool EndChat(char *message);
};