#pragma once
#include "Comms.h"

using namespace std;

class Client : public Comms {
private:
    std::string SendMessage() override;
    void ReceiveMessage(char* buf, int size) override;
public:
    Client()= default;
    void OpenSocket() override;
    void ConnectSocket();
    void StartChat() override;
};