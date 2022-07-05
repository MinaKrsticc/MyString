#include <iostream>
#include "my_string.h"
#include <string.h>
using namespace std;

namespace my_string
{

MyString::MyString()
{
    this->stringValue = nullptr;
}

MyString::~MyString()
{
    if(this->stringValue == nullptr)
        delete this->stringValue;
}

MyString::MyString(char* newString)
{
    int lenght = strlen(newString);
    this->stringValue = new char[lenght];
    strcpy(this->stringValue, newString);
}

MyString::MyString(const MyString& copy)
{
    int lenght = strlen(copy.stringValue);
    this->stringValue = new char[lenght];
    strcpy(this->stringValue, copy.stringValue);
}

ostream& MyString::operator<<(ostream& out)
{
    out << this->stringValue ;
    return out;
}

istream& MyString::operator>>(istream& in)
{
    cout << "Please enter the numerator part: ";
    in >> this->stringValue;
    return in;
}

bool MyString::operator==(const MyString& rhs)
{
    return this->stringValue == rhs.stringValue;
}

MyString MyString::operator+(const MyString& rhs)
{
    rhs.stringValue = this->stringValue + rhs.stringValue ;
    return rhs.stringValue;

}

char* MyString::getStringValue()
{
    return this->stringValue;
}

void MyString::setStringValue(char* newStringValue)
{
    this->stringValue = newStringValue;
}
};
