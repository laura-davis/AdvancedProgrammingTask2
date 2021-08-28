#include "Toggle.h"
#include "Client.h"
#include "Server.h"

int main() {
    if (SERVER) { // Use pre-processor directive to check if main function should be executed as Server or Client
        try {
            cout << "Starting chat application; YOU are the Server.  "; // Output message confirming that Server side is running
            auto *server = new Server(); // Instantiate new Server class object
            server->OpenSocket(); // Call various Server functions
            server->BindSocket();
            server->ListenSocket();
            server->AcceptSocket();
            server->StartChat();
        }
        catch (...) {
            throw GenericErrorException(); // Output generic error message if one occurs
        }
    } else {
        try {
            cout << "Starting chat application; YOU are the Client.  Enter 'QUIT' at any time to end the conversation." << endl;
            auto *client = new Client(); // Instantiate new Client class object
            client->OpenSocket(); // Call various Client functions
            client->ConnectSocket();
            client->StartChat();
        }
        catch (...) {
            throw GenericErrorException(); // Output generic error message if one occurs
        }
    }
}