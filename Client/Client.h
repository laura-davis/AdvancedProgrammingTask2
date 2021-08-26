#pragma once
#include "Comms.h"
#include "Exception.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <string>
#include <pcap/socket.h>

using namespace std;

class Client : public Comms {
private:
    string SendMessage() override;
    void ReceiveMessage(char* buf) override;
public:
    Client()= default;
    void ConnectSocket();
    void StartChat() override;
};