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
    char *str;
    int lenght = strlen(rhs.stringValue);
    int lenThis = strlen(this->stringValue);
    //this->stringValue = new char[lenght];
    str = new char[lenThis+lenght];
    strcpy(str, rhs.stringValue);
    strcat(this->stringValue, str);
}

int MyString::length( MyString& str)
{
    int i = 0;
    while(str.stringValue[i] != '\0')
    {
        i++;
    }
    return i;
}

void MyString::cat(char* newString)
{
    int lenght = strlen(newString);
    this->stringValue = new char[lenght];
    strcat(this->stringValue, newString);
}

MyString MyString::substring(int pos, int length)
{
    MyString newStr;
    newStr.stringValue = new char[length];
    int i = 0;
    int len = strlen(this->stringValue);
    if(length < len)
    {
        while(this->stringValue[i] != '\0')
        {
            if(pos == i)
            {
                for(i = pos; i < length; i++)
                {
                    newStr.stringValue[i] = this->stringValue[i];
                }
            }
            i++;
        }
    }
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
