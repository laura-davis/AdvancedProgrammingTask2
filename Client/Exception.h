#pragma once
#include <exception>
#include <string>

using namespace std;

class OpenSocketException : public exception {
public:
    const char *what() const noexcept override {
        return "Error opening socket";
    }
};

class CloseSocketException : public exception {
public:
    const char *what() const noexcept override {
        return "Error closing socket";
    }
};

class GetUserInputException : public exception {
public:
    const char *what() const noexcept override {
        return "Error getting user input";
    }
};

class SendMessageException : public exception {
public:
    const char *what() const noexcept override {
        return "Error sending message";
    }
};

class ReceiveMessageException : public exception {
public:
    const char *what() const noexcept override {
        return "Error receiving message";
    }
};

class ConnectingToSocketException : public exception {
public:
    const char *what() const noexcept override {
        return "Error connecting to socket";
    }
};

class BindingToSocketException : public exception {
public:
    const char *what() const noexcept override {
        return "Error binding to socket";
    }
};

class ListeningToSocketException : public exception {
public:
    const char *what() const noexcept override {
        return "Error listening to socket";
    }
};

class AcceptingSocketException : public exception {
public:
    const char *what() const noexcept override {
        return "Error accepting socket";
    }
};