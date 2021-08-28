#pragma once
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

class Comms {
protected:
    int serverSocket{};
    struct sockaddr_in socketAddress{};
    int ERROR = -1;
    int PORT = 54000;
    int BUF_SIZE = 1024;
public:
    Comms() = default;
    void OpenSocket();
    void CloseSocket() const;
    static string GetInput();
    virtual string SendMessage() = 0;
    virtual void ReceiveMessage(char* buffer, int size) = 0;
    virtual void StartChat() = 0;
    static void EndChat();
    static bool Quit(char* message);
};