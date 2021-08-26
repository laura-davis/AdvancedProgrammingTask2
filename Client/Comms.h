// TODO - add notes everywhere
// TODO - complete readme file

#pragma once

#include <string>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include "Exception.h"

using namespace std;

class Comms {
protected:
    // TODO - revisit these variables especially sockaddr_in and buffer size
    int ERROR = -1;
    int BUFFER_SIZE = 200;
    int port = 54000; // Set to 54000?
    int sock{}; // SocketRef
    string ipAddress; // = "127.0.0.1"; // Local IP address - do we need this?
    struct sockaddr_in hint{}; // SocketAddress
    string input; // need this?
    static string GetUserInput(); // virtual?
    virtual string SendMessage() = 0;
    virtual void ReceiveMessage(char *buf) = 0; // need buffer size?
    static void PrintError(const string &error) {
        cout << error << endl;
    }

public:
    // TODO - revisit constructor and sockaddr_in
    Comms() = default;
    sockaddr_in SetUpHint();
    void OpenSocket();
    void CloseSocket() const;
    virtual void StartChat() = 0;
    static bool EndChat(char *message);
};