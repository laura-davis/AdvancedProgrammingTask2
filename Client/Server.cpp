#include "Server.h"

Server::Server() {
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_addr.s_addr = htons(INADDR_ANY);
    socketAddress.sin_port = htons(PORT);
}

string Server::SendMessage() {
    string input = GetInput();
    if (send(clientSocketRef, input.c_str(), input.size() + 1, 0) == ERROR) {
        cerr << "Error sending message" << endl;
        exit(7);
    }
    return input;
}

void Server::ReceiveMessage(char *buffer, int size) {
    if (recv(clientSocketRef, buffer, size, 0) == ERROR) {
        cout << "Error receiving message" << endl;
        exit(8);
    } else {
        cout << "Client: " << endl;
    }
}

void Server::BindSocket() {
    if (::bind(socketRef, (struct sockaddr *) &socketAddress, sizeof(socketAddress)) == ERROR) {
        cout << "Error binding connection, the socket has already been established..." << endl;
        exit(9);
    }
    cout << "Socket bound" << endl;
}

void Server::ListenSocket() {
    if(listen(socketRef, SOMAXCONN) == ERROR) {
        cout << "Error listening to port" << endl;
        exit(10);
    }
    cout << "Listening on port: " << PORT << endl;
}

void Server::AcceptSocket() {
    sockaddr_in from{};
    socklen_t clientSocketLength;
    clientSocketLength = sizeof(from);
    clientSocketRef = accept(socketRef, (sockaddr *) &from, &clientSocketLength);
    if (clientSocketRef == ERROR) {
        cout << "Error accepting" << endl;
        exit(11);
    }
}

void Server::StartChat() {
    while (true) {
        char buffer[BUFFER_SIZE];
        ReceiveMessage(buffer, BUFFER_SIZE);
        cout << buffer << endl;
        if (Quit(buffer)) {
            EndChat();
            break;
        }
        string input = SendMessage();
        char input_string[input.length() + 1];
        strcpy(input_string, input.c_str());
        if (Quit(input_string)) {
            EndChat();
            break;
        }
    }
    CloseSocket();
}