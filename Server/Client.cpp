#include "Client.h"
#include "Exception.h"

string Client::SendMessage() {
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

void Client::ReceiveMessage(char *buf) {
    try {
        if ((recv(sock, buf, 200, 0)) == ERROR) {
            throw ReceiveMessageException();
        }
        cout << "Server: " << endl;
    }
    catch (ReceiveMessageException &e) {
        PrintError(e.what());
    }
}

// TODO - revisit this
void Client::ConnectSocket() {
    try {
        if (connect(sock, (struct sockaddr *) &hint, sizeof(hint)) == ERROR) {
            throw ConnectingToSocketException();
        }
    }
    catch (ConnectingToSocketException &e) {
        PrintError(e.what());
    }
}

void Client::StartChat() {
    do {
        input = SendMessage();
        char textInput[input.length() + 1];
        strcpy(textInput, input.c_str());
        if(EndChat(textInput)) {
        CloseSocket();
        }
        char buf[4096];
        ReceiveMessage(buf);
        cout << buf << endl;
        if (EndChat(textInput)) {
            CloseSocket();
        }
    } while(true);
}