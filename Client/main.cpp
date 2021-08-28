#include "Toggle.h"
#include "Client.h"
#include "Server.h"

int main() {
    if (SERVER) {
        try {
            cout << "Starting chat application; YOU are the Server." << endl;
            auto *server = new Server();
            server->OpenSocket();
            server->BindSocket();
            server->ListenSocket();
            server->AcceptSocket();
            server->StartChat();
        }
        catch (...) {
            cout << "An error occurred" << endl;
            exit(5);
        }
    } else {
        try {
            cout << "Starting chat application; YOU are the Client.  Enter 'QUIT' at any time to end the conversation." << endl;
            auto *client = new Client();
            client->OpenSocket();
            client->ConnectSocket();
            client->StartChat();
            exit(6);
        }
        catch (...) {
            cout << "An error occurred" << endl;
        }
    }
}