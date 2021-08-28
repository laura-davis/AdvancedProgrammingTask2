#include "Client.h"

Client::Client() {
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(PORT);
}

void Client::ConnectSocket() {
    if (connect(serverSocket, (struct sockaddr *) &socketAddress, sizeof(socketAddress)) == ERROR) {
        cout << "Error connecting to socket" << endl;
    }
    cout << "Connected via port number: " << PORT << endl;
}

string Client::SendMessage() {
    string input = GetInput();
    if (send(serverSocket, input.c_str(), input.size() + 1, 0) == ERROR) {
        cerr << "Error sending message" << endl;
    }
    return input;
}

void Client::ReceiveMessage(char *buf, int size) {
    if (recv(serverSocket, buf, size, 0) == ERROR) {
        cout << "Error receiving message" << endl;
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
        char buf[BUF_SIZE];
        ReceiveMessage(buf, BUF_SIZE);
        cout << buf << endl;
        if (Quit(buf)) {
            EndChat();
            break;
        }
    }
    CloseSocket();
}