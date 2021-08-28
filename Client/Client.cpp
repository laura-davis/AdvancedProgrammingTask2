#include "Client.h"

Client::Client() {
    server_address.sin_family = AF_INET; // Use IPv4 domain
    server_address.sin_port = htons(PORT); // Convert port number from host to network short
}

void Client::ConnectSocket() {
    try {
        if (connect(client, (struct sockaddr *) &server_address, sizeof(server_address)) ==
            ERROR) { // If unable to connect to socket...
            throw ConnectSocketException(); // ...Throw exception
        }
    }
    catch (ConnectSocketException &e) { // Catch exception
        PrintError(e.what()); // Print error
    }
    cout << "Connected via port number: " << PORT << endl; // ...Otherwise, output connection details
}

string Client::GetUserInput() {
    string input; // Instantiate string variable for storing input
        cout << "Client: "; // Prompt user for input
        getline(cin, input); // Store the next line in the input variable
    return input; // Return input
}

string Client::SendMessage() {
    string input = GetUserInput(); // Assign value returned from GetInput() function to string input variable
    try {
        if (send(client, input.c_str(), input.size() + 1, 0) ==
            ERROR) { // If an attempt to send the message from the Client fails...
            throw SendMessageException(); // ...Throw exception
        }
    }
    catch (SendMessageException &e) { // Catch exception
        PrintError(e.what()); // Print error
    }
    return input; // Otherwise return input
}

void Client::ReceiveMessage(char *buffer, int size) {
    try {
        if (recv(client, buffer, size, 0) == ERROR) { // If the client fails to receive the message...
            throw ReceiveMessageException(); // ...Throw exception
        } else {
            cout << "Server: "; // Otherwise print out "Server" to indicate the next message has been received from the Server
        }
    }
    catch (ReceiveMessageException &e) { // Catch exception
        PrintError(e.what()); // Print error
    }
}

void Client::StartChat() {
    while (true) {
        string input = SendMessage(); // Call SendMessage function using data returned by GetUserInput function
        char input_string[input.length() +
                          1]; // Instantiate input_string array, adding 1 to the length of text input as arrays are zero-indexed
        strcpy(input_string, input.c_str()); // Use string copy function to copy input
        if (Quit(input_string)) { // Check if user input is equal to "QUIT"
            EndChat(); // If so, call EndChat function to output appropriate message
            break;
        }
        char buffer[BUFFER_SIZE]; // Instantiate buffer array to a size of 1024
        ReceiveMessage(buffer, BUFFER_SIZE); // Call the ReceiveMessage function with the message and size received
        cout << buffer << endl; // Output message from buffer
        if (Quit(buffer)) { // Check if user input is equal to "QUIT"
            EndChat(); // If so, call EndChat function to output appropriate message
            break;
        }
    }
    CloseSocket(); // Call CloseSocket function to close Client file descriptor
}