#include "Comms.h"

void Comms::PrintError(const string &error) {
    std::cout << error << std::endl;
}

std::string Comms::GetUserInput() {
    std::string userInput; // Initialise string for capturing user input
    std::cout << "> "; // Prompt user for input
    try {
        std::getline(std::cin, userInput); // Capture entire line of text and assign it to variable
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
        std::cout << "Connection between client and server terminated" << std::endl;
    }
    catch (CloseSocketException &e) {
        PrintError(e.what());
    }
}

bool Comms::EndChat(char *message) {
    return strcmp(message, "QUIT") == 0; // Check if user enters "QUIT"
}