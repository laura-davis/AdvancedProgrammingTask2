#include "Server.h"

Server::Server() {
    server_address.sin_family = AF_INET; // Domain address (IPv4)
    server_address.sin_addr.s_addr = htons(INADDR_ANY); // Host IP Address
    server_address.sin_port = htons(PORT); // Convert port number from host to network short
}

string Server::SendMessage() {
    string input = GetUserInput(); // Assign value returned from GetInput() function to string input variable
    try {
        if (send(server, input.c_str(), input.size() + 1, 0) ==
            ERROR) { // If an attempt to send the message from the Server fails...
            throw SendMessageException(); //...Throw exception
        }
    } catch (SendMessageException &e) { // Catch exception
        PrintError(e.what()); // Print error
    }
    return input; // Otherwise return input
}

void Server::ReceiveMessage(char *buffer, int size) {
    try {
        if (recv(server, buffer, size, 0) == ERROR) { // If the server fails to receive the message...
            throw ReceiveMessageException(); // ...Throw exception
        } else {
            cout
                    << "Client: "; // Otherwise print out "Client" to indicate the next message has been received from the Client
        }
    }
    catch (ReceiveMessageException &e) { // Catch exception
        PrintError(e.what()); // Print error
    }
}

void Server::BindSocket() {
    try {
        if (::bind(client, (struct sockaddr *) &server_address, sizeof(server_address)) ==
            ERROR) { // If there is a problem binding the socket to the address...
            throw BindSocketException(); // ...Throw exception
        }
    } catch (BindSocketException &e) { // Catch exception
        PrintError(e.what()); // Print error
    }
    cout << "Socket bound." << endl; // Otherwise confirm that binding was successful
}

void Server::ListenSocket() {
    try {
        if (listen(client, SOMAXCONN) == ERROR) { // Mark the socket for listening.  If there is an error...
            cout << "Error listening to port" << endl; // ...Throw exception
        }
    }
    catch (ListenSocketException &e) {
        PrintError(e.what());
    }
    cout << "Listening on port: " << PORT << endl << "Waiting for message from the Client..."
         << endl; // Otherwise output message confirming that Server is listening on specific port (54000 in this case)
}

void Server::AcceptSocket() {
    sockaddr_in client_address{}; // Instantiate structure for containing client IP address
    socklen_t client_socket_length = sizeof(client_address); // Instantiate int for holding socket length
    try {
        server = accept(client, (sockaddr *) &client_address,
                        &client_socket_length); // Try to establish connection with Client
        if (server == ERROR) { // If unable to connect to Client...
            throw AcceptSocketException(); // ...Throw exception
        }
    }
    catch (AcceptSocketException &e) {
        PrintError(e.what());
    }
}

string Server::GetUserInput() {
    string input; // Instantiate string variable for storing input
    cout << "Server: "; // Prompt user for input
    getline(cin, input); // Store the next line in the input variable
    return input; // Return input
}

void Server::StartChat() {
    while (true) {
        char buffer[BUFFER_SIZE]; // Instantiate buffer array to a size of 1024
        ReceiveMessage(buffer, BUFFER_SIZE); // Call the ReceiveMessage function with the message and size received
        cout << buffer << endl; // Output message from buffer
        if (Quit(buffer)) { // Check if user input is equal to "QUIT"
            EndChat(); // If so, call EndChat function to output appropriate message
            break;
        }
        string input = SendMessage(); // Call SendMessage function using data returned by GetUserInput function
        char input_string[input.length() +
                          1]; // Instantiate input_string array, adding 1 to the length of text input as arrays are zero-indexed
        strcpy(input_string, input.c_str()); // Use string copy function to copy input
        if (Quit(input_string)) { // Check if user input is equal to "QUIT"
            EndChat(); // If so, call EndChat function to output appropriate message
            break;
        }
    }
    CloseSocket(); // Call CloseSocket function to close Client file descriptor}
}