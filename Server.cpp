#include "Server.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0); //	Create socket using socket function
    if (sock == -1) { // If unable to create socket...
        cerr << "Error creating socket" << endl; // ...Output error message
        return 1; // ...and return error code
    }
    int port = 54000; // Port specified in client code
    string ipAddress = "127.0.0.1"; // Local IP address
    sockaddr_in hint{}; // Initialise hint from the client
    hint.sin_family = AF_INET; // Use IPv4 domain
    hint.sin_port = htons(port); // Convert port number from host to network short
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr); // Convert IP address to an array of integers
    int connectRes = connect(sock, (sockaddr *) &hint, sizeof(hint)); // Connect to remote machine
    if (connectRes == -1) { // If unable to connect...
        cerr << "Error connecting" << endl; // ...Output error message
        return 2; // ...and return error code
    }
    char buf[4096]; // Initialise buffer
    string userInput; // Initialise string for capturing user input
    do {
        cout << "> "; // Prompt user for input
        getline(cin, userInput); // Capture entire line of text
        int sendRes = send(sock, userInput.c_str(), userInput.size()+1, 0);
        if (sendRes == -1) { // If unable to send to server...
            cerr << "Error sending to server" << endl; // ...Output error message
            continue; // ...and go back to try again
        }
        memset(buf, 0, 4096); // Clear buffer
        int bytesReceived = recv(sock, buf, 4096, 0); // Initialise bytesRecv variable, ready to receive data
        cout << "Server: " << string(buf, bytesReceived) << "\r\n";
    } while (true);
close(sock); // Close socket
}