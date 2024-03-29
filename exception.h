#include <exception>
#include "my_string.h"

#ifndef EXCEPTION_H
#define EXCEPTION_H
using namespace std;
using namespace my_string;

namespace my_string {

struct my_base_exception : std::exception {

    string errorMessage;

    my_base_exception()
    {
        errorMessage = "exception: ";
    }
    my_base_exception(const char* message) : errorMessage("my_base_exception")
    {
        errorMessage += message;
    }

    const char* what() const noexcept
    {
        return errorMessage.c_str();
    }
};

struct NullPointerException : std::exception {
    const char* what() const noexcept {return "NullPointerException\n";}
};

struct NegativeArgumentException : std::exception {
    const char* what() const noexcept {return "NegativeArgumentException\n";}
};

struct InvalidArgumentException : std::exception {
    const char* what() const noexcept {return "InvalidArgumentException\n";}
};

struct NotCorrectLenthSubStringException : std::exception {
    const char* what() const noexcept {return "NotCorrectLenthSubStringException\n";}
};

struct WrongArgumentException : std::exception {
    const char* what() const noexcept {return "WrongArgumentException\n";}
};

}
#endif // EXCEPTION_H
