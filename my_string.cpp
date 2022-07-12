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

MyString::MyString(const char* newString)
{
    int lenght = strlen(newString);
    this->stringValue = new char[lenght + 1];
    strcpy(this->stringValue, newString);
}

MyString::MyString(const MyString& copy)
{
    int lenght = strlen(copy.stringValue);
    this->stringValue = new char[lenght + 1];
    strcpy(this->stringValue, copy.stringValue);
}

ostream& operator<<(ostream& out, const MyString& str)
{
    out << str.stringValue;
    return out;
}

istream& operator>>(istream& in, const MyString& str)
{
    in >> str.stringValue;
    return in;
}

bool MyString::operator==(const MyString& rhs)
{
    return this->stringValue == rhs.stringValue;
}

MyString MyString::operator+(const MyString& rhs)
{
    //MyString strMy(this->stringValue);
    MyString strMy(*this);
    //MyString strMy = *this;
    strMy.cat(rhs.stringValue);
    /*int lenght = strlen(rhs.stringValue);
    int lenThis = strlen(this->stringValue);
    strMy.stringValue = new char [lenThis + lenght + 1];
    strcpy(strMy.stringValue, this->stringValue);
    //delete [] this->stringValue;
    strcat(strMy.stringValue, rhs.stringValue);
    //this->stringValue = strMy.stringValue ;*/
    return strMy;

    /* char str = new char[lenThis + lenght + 1];
    strcpy(str, this->stringValue);
    strcat(str, rhs.stringValue);
    strcpy(this->stringValue, str);
    this->stringValue = str;
    delete [] str;
    return this->stringValue;*/
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

int MyString::len()
{
    int n = strlen(this->stringValue);
    return n;
}

void MyString::cat(char* newString)
{
    int lenght = strlen(newString);
    int lenThis = strlen(this->stringValue);
    char *str = new char[lenght + lenThis + 1];
    strcpy(str, this->stringValue);
    delete [] this->stringValue;
    strcat(str, newString);
    this->stringValue = str;
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
                newStr.stringValue[length] = '\0';
            }
            i++;
        }
    }
    return newStr.stringValue;
}

int MyString::stringcmp(char* a, char* b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);
    int i = 0;

    if(lenA == lenB)
    {
        while (i < lenA)
        {
            if(a[i] == b[i])
            {
                i++;
            }
        }
        if(i == lenA)
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}

bool MyString::isSubstring(char* str, char* substr)
{
    int n = strlen(str);
    int m = strlen(substr);
    int i;
    int j = 0;
    //char pom;
    char* pomString;
    pomString =  new char [m];
    // pom = substr[j];

    for(i = 0; i < n; i++)
    {
        if(substr[j] == str[i])
        {
            pomString[j] = substr[j];
            j++;
            if(j >= m)
            {
                if(strcmp(substr, pomString) == 0)
                {
                    return true;
                }
            }
        }
        return false;
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
