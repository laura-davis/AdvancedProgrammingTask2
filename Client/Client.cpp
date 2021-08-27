#include "Client.h"

string Client::SendMessage() {
    string input = GetUserInput();
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

void Client::ReceiveMessage(char *buf, int size) {
    try {
        if ((recv(sock, buf, size, 0)) == ERROR) {
            throw ReceiveMessageException();
        }
        cout << "Server: " << endl;
    }
    catch (ReceiveMessageException &e) {
        PrintError(e.what());
    }
}

void Client::OpenSocket() {
    try {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        cout << "Client socket has been created" << endl;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
    }
    catch (OpenSocketException &e) {
        PrintError(e.what());
    }
}

void Client::ConnectSocket() {
    try {
        if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == ERROR) {
            throw ConnectingToSocketException();
        }
    }
    catch (ConnectingToSocketException &e) {
        PrintError(e.what());
    }
}

void Client::StartChat() {
    do {
        string input = SendMessage();
        char textInput[input.length() + 1];
        strcpy(textInput, input.c_str());
        if (EndChat(textInput)) {
            CloseSocket();
            break;
        }
        char buf[BUF_SIZE];
        ReceiveMessage(buf, BUF_SIZE);
        cout << buf << endl;
        if (EndChat(textInput)) {
            CloseSocket();
            break;
        }
    } while (true);
}