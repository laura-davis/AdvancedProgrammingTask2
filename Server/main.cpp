#include "Toggle.h"
#include "Client.h"
#include "Server.h"

using namespace std;

int main() {
    std::cout << "Starting chat application; you are the Server..." << std::endl;
    std::cout << "Type 'QUIT' at any time to terminate the connection between the Client and the Server" << std::endl;
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
            std::cout << "An error occurred" << std::endl;
        }
    } else {
        try {
            auto *client = new Client();
            client->OpenSocket();
            client->ConnectSocket();
            client->StartChat();
        }
        catch (...) {
            std::cout << "An error occurred" << std::endl;
        }
    }
}