#include "Server.h"

Server::Server() {
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_addr.s_addr = htons(INADDR_ANY);
    socketAddress.sin_port = htons(PORT);
}

string Server::SendMessage() {
    string input = GetInput();
    if (send(clientSocket, input.c_str(), input.size() + 1, 0) == ERROR) {
        cerr << "Error sending message" << endl;
    }
    return input;
}

void Server::ReceiveMessage(char *buf, int size) {
    if (recv(clientSocket, buf, size, 0) == ERROR) {
        cout << "Error receiving message" << endl;
    } else {
        cout << "Client: ";
    }
}

void Server::BindSocket() {
    if (::bind(serverSocket, (struct sockaddr *) &socketAddress, sizeof(socketAddress)) == ERROR) {
        cout << "Error binding connection, the socket has already been established..." << endl;
    }
    cout << "Socket bound" << endl;
}

void Server::ListenSocket() {
    if(listen(serverSocket, SOMAXCONN) == ERROR) {
        cout << "Error listening to port" << endl;
    }
    cout << "Listening on port: " << PORT << endl;
}

void Server::AcceptSocket() {
    sockaddr_in from{};
    socklen_t clientSocketLength;
    clientSocketLength = sizeof(from);
    clientSocket = accept(serverSocket, (sockaddr *) &from, &clientSocketLength);
    if (clientSocket == ERROR) {
        cout << "Error accepting" << endl;
    }
}

void Server::StartChat() {
    while (true) {
        char buffer[BUF_SIZE];
        ReceiveMessage(buffer, BUF_SIZE);
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