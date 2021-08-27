#include "Comms.h"

void Comms::PrintError(const string &error) {
    cout << error << endl;
}

string Comms::GetUserInput() {
    string userInput; // Initialise string for capturing user input
    cout << "> "; // Prompt user for input
    try {
        getline(cin, userInput); // Capture entire line of text and assign it to variable
        return userInput; // Return user input
    }
    catch (GetUserInputException &e) {
        PrintError(e.what());
        return "Error";
    }
}

void Comms::CloseSocket() const {
    try {
        close(port); // Close socket
        cout << "Connection between client and server terminated" << endl;
    }
    catch (CloseSocketException &e) {
        PrintError(e.what());
    }
}

bool Comms::EndChat(char *message) {
    return strcmp(message, "QUIT") == 0; // Check if user enters "QUIT"
}