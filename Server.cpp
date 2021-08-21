#include "Server.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>
#include <string>

using namespace std;

int main() {
    int listening = socket(AF_INET, SOCK_STREAM, 0); //	Create socket using socket function
    if (listening == -1) { // If socket doesn't exist...
        throw CannotCreateSocketException(); // ...Output error message
    }

    sockaddr_in hint{}; // Initialise hint from the server
    hint.sin_family = AF_INET; // Use IPv4 domain
    hint.sin_port = htons(54000); // Convert port number from host to network short
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr); // Convert IP address to an array of integers
    bind(listening, (sockaddr *) &hint, sizeof(hint)); // Bind IP address to socket
    if (::bind(listening, (sockaddr *) &hint, sizeof(hint)) == -1) { // If unable to bind...
        throw CannotBindToPortException(); // ...Output error message
    }
    listen(listening, SOMAXCONN); // Mark socket for listening
    if (listen(listening, SOMAXCONN) == -1) { // If unable to listen...
        throw CannotListenToPortException(); // ...Output error message
    }
    sockaddr_in client{}; // Initialise client
    socklen_t clientSize = sizeof(client); // Get size of client
    int clientSocket = accept(listening, (sockaddr *) &client, &clientSize); // Accept incoming connection
    char host[NI_MAXHOST]; // Client's remote name
    char svc[NI_MAXSERV]; // Service (port) that client is connected on
    memset(host, 0, NI_MAXHOST); // Clean up host memory
    memset(svc, 0, NI_MAXSERV); // Clean up service memory

    if (clientSocket == -1) { // If unable to accept connection...
        throw CannotConnectToClientException(); // ...Output error message
    }
    if (getnameinfo((sockaddr *) &client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV, 0) == 0) { // If it is possible to get remote name
        cout << host << " connected on port " << svc << endl; // ...Output remote name
    } else { // Otherwise...
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST); // Convert network address to string
        cout << host << " connected on " << ntohs(client.sin_port) << endl; // Print connection details
    }

    close(listening); // Close listening socket

    char buf[4096]; // Initialise buffer

    while (true) { // While buffer exists, wait for client to send data
        memset(buf, 0, 4096); // Clear buffer
        long bytesRecv = recv(clientSocket, buf, 4096, 0); // Initialise bytesRecv variable, ready to receive data
        if (bytesRecv == -1) // If there is an error...
        {
            cout << "Error receiving data or connection is closed" << endl; // ...Output error message
            break;
        }
        if (bytesRecv == 0) { // If no data is received
            cout << "Client disconnected" << endl; // ...Output error message
            break;
        }
        cout << "Server: " << string(buf, 0, bytesRecv) << endl; // Output message details
        send(clientSocket, buf, bytesRecv -1, 0); // Echo message back to client
    }
    close(clientSocket); // Close client socket

    return 0;
}