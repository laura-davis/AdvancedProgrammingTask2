#include "Comms.h"

//void Comms::OpenSocket() {
//    if((socketRef = socket(AF_INET, SOCK_STREAM, 0) == ERROR)) {
//        cout << "Error establishing socket" << endl;
//    }
//    cout << "Socket has been created" << endl;
//}

void Comms::OpenSocket() {
    socketRef = socket(AF_INET, SOCK_STREAM, 0);
    if (socketRef == -1) {
        cout << "error" << endl;
        exit(1);
    }
}

void Comms::CloseSocket() const {
    close(socketRef);
}

string Comms::GetInput() {
    string input;
    cout << "Your message: " << endl;
    getline(cin, input);
    return input;
}

bool Comms::Quit(char* message) {
    return strcmp(message, "QUIT") == 0;
}

void Comms::EndChat() {
        cout << "Connection between the client and server has been terminated" << endl;
}