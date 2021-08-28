#include "Comms.h"

void Comms::OpenSocket() {
    client = socket(AF_INET, SOCK_STREAM,
                    0); // Socket function takes the address domain (IPv4), socket type (TCP) and protocol; system will choose default
    try {
        if (client == ERROR) { // If there is an error establishing connection...
            throw OpenSocketException(); // ...Throw exception
        }
    }
    catch (OpenSocketException &e) { // Catch exception
        PrintError(e.what()); // Print error
    }
}

void Comms::CloseSocket() const {
    close(client); // Close client file descriptor
}

bool Comms::Quit(char *message) {
    return strcmp(message, "QUIT") == 0; // Check if user has entered "QUIT"; if yes, return true
}

void Comms::EndChat() {
    cout << "Connection between the client and server has been terminated"
         << endl; // Output message to indicate that the connection has been terminated
}

void Comms::PrintError(const string& error) {
    cout << "Error: " << error << endl;
}