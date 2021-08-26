#include "Comms.h"

string Comms::GetUserInput() {
    string userInput; // Initialise string for capturing user input
    cout << "> "; // Prompt user for input
    try {
        getline(cin, userInput); // Capture entire line of text and assign it to variable
        return userInput; // Return user input
    }
    catch (GetUserInputException &e){
        PrintError(e.what());
        return "Error";
    }
}

// TODO - look at constructor

// TODO - revisit this
sockaddr_in Comms::SetUpHint() {
    hint.sin_family = AF_INET; // Use IPv4 domain
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr); // Convert IP address to an array of integers
    hint.sin_port = htons(port); // Convert port number from host to network short
    return hint; // Return sockaddr_in
}

// TODO - revisit this
void Comms::OpenSocket() {
    try {
        sock = socket(AF_INET, SOCK_STREAM, 0); //	Create socket using socket function
    }
    catch (OpenSocketException &e) {
        PrintError(e.what());
    }
}

void Comms::CloseSocket() const {
    try {
        close(sock); // Close socket
        cout << "Connection between client and server terminated" << endl;
    }
    catch (CloseSocketException &e) {
        PrintError(e.what());
    }
}

bool Comms::EndChat(char *message) {
    return strcmp(message, "QUIT") == 0; // Check if user enters "QUIT"
}