#pragma once
#include <exception>
#include <string>

using namespace std;

#pragma once

#include <exception>
#include <string>

using namespace std;

class CannotCreateSocketException : public exception {
public:
    const char *what() const noexcept override {
        return "Error creating socket";
    }
};

class CannotConnectToServerException : public exception {
public:
    const char *what() const noexcept override {
        return "Error connecting to server";
    }
};

class CannotBindToPortException : public exception {
public:
    const char *what() const noexcept override {
        return "Error binding to port";
    }
};

class CannotListenToPortException : public exception {
public:
    const char *what() const noexcept override {
        return "Error listening to port";
    }
};

class CannotConnectToClientException : public exception {
public:
    const char *what() const noexcept override {
        return "Error connecting to client";
    }
};