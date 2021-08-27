#include "Toggle.h"
#include "Client.h"
#include "Server.h"

int main() {
    cout << "Starting chat application; you are the Server..." << endl;
    cout << "Type 'QUIT' at any time to terminate the connection between the Client and the Server" << endl;
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
            client->OpenSocket();
            client->ConnectSocket();
            client->StartChat();
        }
        catch (...) {
            cout << "An error occurred" << endl;
        }
    }
}