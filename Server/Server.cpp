#include "Server.h"

std::string Server::SendMessage() {
    std::string input = GetUserInput();
    try {
        if ((send(clientSock, input.c_str(), input.size() + 1, 0)) == ERROR) { // Send to client; add 1 for trailing 0
            throw SendMessageException();
        }
        return input;
    }
    catch (SendMessageException &e) {
        PrintError(e.what());
        return "Error";
    }
}

void Server::ReceiveMessage(char *buf, int size) {
    try {
        if ((recv(clientSock, buf, size, 0)) == ERROR) {
            throw ReceiveMessageException();
        }
        std::cout << "Client: " << std::endl;
    }
    catch (ReceiveMessageException &e) {
        PrintError(e.what());
    }
}

void Server::OpenSocket() {
    try {
        socketRef = socket(AF_INET, SOCK_STREAM, 0);
        std::cout << "Client socket has been created" << std::endl;
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = htons(INADDR_ANY);
        server_addr.sin_port = htons(port);
    }
    catch (OpenSocketException &e) {
        PrintError(e.what());
    }
}

void Server::BindToSocket() {
    try {
        if ((::bind(socketRef, (struct sockaddr *) &server_addr, sizeof(server_addr))) == ERROR) {
            throw ReceiveMessageException();
        }
    }
    catch (BindingToSocketException &e) {
        PrintError(e.what());
    }
}

void Server::ListenToSocket() {
    try {
        if (listen(socketRef, SOMAXCONN) == ERROR) {
            throw ListeningToSocketException();
        }
        std::cout << "Listening on port " << port << std::endl;
    }
    catch (ListeningToSocketException &e) {
        PrintError(e.what());
    }
}

void Server::AcceptSocket() {
    clientSockLength = sizeof(client);
    try {
        if ((clientSock =
                     accept(socketRef, (sockaddr *) &client, &clientSockLength) == ERROR)) { // Accept incoming connection {
            throw AcceptingSocketException();
        }
    }
    catch (AcceptingSocketException &e) {
        PrintError(e.what());
    }
}

void Server::StartChat() {
    do {
        char buf[BUF_SIZE];
        ReceiveMessage(buf, BUF_SIZE);
        std::cout << buf << std::endl;
        if (EndChat(buf)) {
            CloseSocket();
            break;
        }
        std::string input = SendMessage();
        char textInput[input.length() + 1];
        strcpy(textInput, input.c_str());
        if (EndChat(textInput)) {
            CloseSocket();
            break;
        }
    } while (true);
}