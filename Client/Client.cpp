#include "Client.h"

Client::Client() {
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(PORT);
}

void Client::ConnectSocket() {
    if (connect(serverSocket, (struct sockaddr *) &socketAddress, sizeof(socketAddress)) == ERROR) {
        cout << "Error connecting to socket" << endl;
        exit(2);
    }
    cout << "Connected via port number: " << PORT << endl;
}

string Client::SendMessage() {
    string input = GetInput();
    if (send(serverSocket, input.c_str(), input.size() + 1, 0) == ERROR) {
        cerr << "Error sending message" << endl;
        exit(3);
    }
    return input;
}

void Client::ReceiveMessage(char *buffer, int size) {
    if (recv(serverSocket, buffer, size, 0) == ERROR) {
        cout << "Error receiving message" << endl;
        exit(4);
    } else {
        cout << "Server: ";
    }
}

void Client::StartChat() {
    while (true) {
        string input = SendMessage();
        char input_string[input.length() + 1];
        strcpy(input_string, input.c_str());
        if (Quit(input_string)) {
            EndChat();
            break;
        }
        char buffer[BUF_SIZE];
        ReceiveMessage(buffer, BUF_SIZE);
        cout << buffer << endl;
        if (Quit(buffer)) {
            EndChat();
            break;
        }
    }
    CloseSocket();
}