#include "Server.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>
#include <string>

string Server::SendMessage() {
    input = GetUserInput();
    try {
        if ((send(sock, input.c_str(), input.size() + 1, 0)) == ERROR) { // Send to client; add 1 for trailing 0
            throw SendMessageException();
        }
        return input;
    }
    catch (SendMessageException &e) {
        PrintError(e.what());
        return "Error";
    }
}

void Server::ReceiveMessage(char *buf) {
    try {
        if ((recv(sock, buf, 200, 0)) == ERROR) {
            throw ReceiveMessageException();
        }
        cout << "Client: " << endl;
    }
    catch (ReceiveMessageException &e) {
        PrintError(e.what());
    }
}

void Server::ListenToSocket() {
    try {
        if (listen(listening, SOMAXCONN) == ERROR) {
            throw ListeningToSocketException();
        }
        cout << "Listening on port " << port << endl;
    }
    catch (ListeningToSocketException &e) {
        PrintError(e.what());
    }
}

// TODO - revisit sock / hint
void Server::BindToSocket() {
    try {
        if ((::bind(listening, (struct sockaddr *) &hint, sizeof(hint))) == ERROR) {
            throw ReceiveMessageException();
        }
    }
    catch (BindingToSocketException &e) {
        PrintError(e.what());
    }
}

void Server::AcceptSocket() {
    sockaddr_in client{}; // Initialise client
    socklen_t clientSize = sizeof(client); // Get size of client
    try {
        if ((clientSocket =
                     accept(listening, (sockaddr *) &client, &clientSize) == ERROR)) { // Accept incoming connection) {
            throw AcceptingSocketException();
        }
    }
    catch (AcceptingSocketException &e) {
        PrintError(e.what());
    }
}

void Server::StartChat() {
    do {
        char buf[4096];
        ReceiveMessage(buf);
        cout << buf << endl;
        if (EndChat(buf)) {
            CloseSocket();
        }
        input = SendMessage();
        char textInput[input.length() + 1];
        strcpy(textInput, input.c_str());
        if (EndChat(textInput)) {
            CloseSocket();
        }
    } while (true);
}