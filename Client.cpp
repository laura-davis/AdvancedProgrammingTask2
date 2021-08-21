#include "Client.h"
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
    // TODO - get rid? Domain = AF_INET (IPv4), Type = Stream Socket (SOCK_STREAM), Protocol = 0
    if (listening == -1) { // If socket doesn't exist...
        cerr << "Error creating socket" << endl; // ...Output error message
        return -1; // ...and return error code
    }

    sockaddr_in hint{}; // Initialise hint from the server
    hint.sin_family = AF_INET; // Use IPv4 domain TODO - Extract this to separate class
    hint.sin_port = htons(54000); // Convert port number from host to network short
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr); // Convert IP address to an array of integers
    if (::bind(listening, (sockaddr*)&hint, sizeof(hint)) == -1) { // If unable to bind hint to port..
        // socket, domain, pointer to socket address, length of address
        cerr << "Error binding to port" << endl; // ...Output error message
        return -2; // ...and return error code
    }
    if (listen(listening, SOMAXCONN) == -1) { // If unable to listen to socket...
        cerr << "Error listening to port" << endl; // ...Output error message
        return -3; // ...and return error code
    }
    sockaddr_in client{}; // Initialise client
    socklen_t clientSize = sizeof(client); //
    char host[NI_MAXHOST]; // Buffer for host
    char svc[NI_MAXSERV]; // Buffer for service
    int clientSocket = accept(listening, (sockaddr *) &client, &clientSize); // Accept incoming connection
    if (clientSocket == -1) { // If unable to accept connection...
        cerr << "Error connecting to client" << endl; // ...Output error message
        return -4; // ...and return error code
    }
    close(listening); // Close listening socket
    memset(host, 0, NI_MAXHOST); // Clean up host memory
    memset(svc, 0, NI_MAXSERV); // Clean up service memory

    int result = getnameinfo((sockaddr *) &client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV,
                             0); // Convert address to computer name and location

    if (result) { // If successful...
        cout << "Host connected on " << svc << endl; // ...Output details of computer
    } else { // Otherwise...
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST); // Convert network address to string
        cout << host << " connected on " << ntohs(client.sin_port) << endl; // Print connection details
    }
    char buf[4096]; // Initialise buffer

    while (true) { // While buffer exists
        memset(buf, 0, 4096); // Clear buffer
        int bytesRecv = recv(clientSocket, buf, 4096, 0); // Initialise bytesRecv variable, ready to receive data
        if (bytesRecv == -1) // If there is an error...
        {
            cout << "Error with connection" << endl; // ...Output error message
            break;
        }
        if (bytesRecv == 0) { // If no data is received
            cout << "Client disconnected" << endl; // ...Output error message
            break;
        }
        cout << "Server: " << string(buf, 0, bytesRecv) << "\r\n"; // Output message details
        send(clientSocket, buf, bytesRecv + 1, 0); // Send message
    }
    close(clientSocket); // Close client socket

    return 0;

}