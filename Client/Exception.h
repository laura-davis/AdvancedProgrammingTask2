#include <exception>
#include <string>

using namespace std;

class ConnectSocketException : public exception {
public:
    const char *what() const noexcept override {
        return "Error connecting to socket";
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

class OpenSocketException : public exception {
public:
    const char *what() const noexcept override {
        return "Error establishing socket";
    }
};

class BindSocketException : public exception {
public:
    const char *what() const noexcept override {
        return "Error binding connection, port may already be in use";
    }
};

class ListenSocketException : public exception {
public:
    const char *what() const noexcept override {
        return "Error listening to port";
    }
};

class AcceptSocketException : public exception {
public:
    const char *what() const noexcept override {
        return "Error accepting connection";
    }
};

class GenericErrorException : public exception {
public:
    const char *what() const noexcept override {
        return "An error occurred";
    }
};

