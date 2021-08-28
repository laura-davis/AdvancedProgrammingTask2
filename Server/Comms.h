#pragma once
#include <iostream> // Various libraries which are common across the Server and Client class are imported here
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <unistd.h>
#include "Exception.h"

using namespace std;

class Comms { // The Client and Server class both extend the Comms class and so will inherit the variables and functions from the parent class
protected:
    int ERROR = -1; // Constant error variable use for exception handling
    int PORT = 54000; // Same port number for Client and Server
    int BUFFER_SIZE = 1024; // Constant buffer size variable for establishing buffers
    int client{}; // Integer variable for the Client and its various calls
    struct sockaddr_in server_address{}; // Structure containing internet address
public:
    Comms() = default; // Default constructor
    void OpenSocket();
    void CloseSocket() const;
    virtual string GetUserInput() = 0; // Virtual functions are "abstract"; simply declared in the parent class and then implemented in the child class
    virtual string SendMessage() = 0;
    virtual void ReceiveMessage(char* buffer, int size) = 0;
    virtual void StartChat() = 0;
    static void EndChat();
    static bool Quit(char* message);
    static void PrintError(const string& error);
};