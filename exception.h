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
    const char* what() const noexcept {return "NotPositiveValueToPosition\n";}
};

struct NotCorrectPositionException : std::exception {
    const char* what() const noexcept {return "NotCorectPosition\n";}
};

struct NotCorrectLenthSubStringException : std::exception {
    const char* what() const noexcept {return "NotCorrectLenthSubString\n";}
};

struct NotPositionInStringException : std::exception {
    const char* what() const noexcept {return "NotPositionInStringException\n";}
};

}
#endif // EXCEPTION_H
