#include <iostream>
#include "Toggle.h"
#include "Client.h"
#include "Server.h"

using namespace std;

int main() {
    cout << "Starting chat application..." << endl;
    cout << "Type 'QUIT' at any time to terminate the connection between the client and the server" << endl << endl;
    if (SERVER) {
        try {
            auto *server = new Server();
            server->OpenSocket();
            server->BindToSocket();
            server->ListenToSocket();
            server->AcceptSocket();
            server->StartChat();
        }
        catch (...) {
            cout << "An error occurred" << endl;
        }
    } else {
        try {
            auto *client = new Client();
            client->SetUpHint();
            client->OpenSocket();
            client->ConnectSocket();
            client->StartChat();
        }
        catch (...) {
            cout << "An error occurred" << endl;
        }
    }
}