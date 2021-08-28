#include "Comms.h"

void Comms::OpenSocket() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == ERROR) {
        cout << "error" << endl;
    }
}

void Comms::CloseSocket() const {
    close(serverSocket);
}

string Comms::GetInput() {
    string input;
    cout << "Your message: ";
    getline(cin, input);
    return input;
}

bool Comms::Quit(char* message) {
    return strcmp(message, "QUIT") == 0;
}

void Comms::EndChat() {
        cout << "Connection between the client and server has been terminated" << endl;
}