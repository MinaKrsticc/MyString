#include <iostream>
#include <exception>
#include "my_string.h"
#include "exception.h"
#include <string.h>
using namespace std;

namespace my_string
{

MyString::MyString()
{
    this->stringValue = nullptr;
}

MyString::MyString(int len)
{
    len = strlen(this->stringValue);
    this->stringValue = new char[len];
    //this->stringValue = nullptr;
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
    if (copy.stringValue == nullptr)
    throw NullPointerException();

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

int MyString::length(MyString& str)
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
    if (newString == nullptr && this->stringValue == nullptr)
    {
        throw NullPointerException();
    }

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
    if (this->stringValue == nullptr)
    {
        throw NullPointerException();
    }

    MyString newStr(length);
    //MyString newStr = new char [length];
    int i = 0;
    int j = 0;
    int len = strlen(this->stringValue);

    if (pos >= 0 && length + pos <= len)
    {
        while(this->stringValue[i] != '\0')
        {
            if(pos == i)
            {
                for(i = pos; i < length + pos; i++)
                {
                    newStr.stringValue[j] = this->stringValue[i];
                    j++;
                }
                newStr.stringValue[length] = '\0';
            }
            i++;
        }
    }
    else
    {
        throw NegativeArgumentException();
        throw NotCorrectPositionException();

    }
    return newStr.stringValue;
}

int MyString::stringcmp(char* a, char* b)
{
    if (a == nullptr && b == nullptr)
    {
    throw NullPointerException();
    }

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

bool MyString::isSubstring(char* substr)
{
    if (substr == nullptr)
    {
    throw NullPointerException();
    }

    int n = strlen(this->stringValue);
    int m = strlen(substr);

    if(n > m)
    {
        throw NotCorrectLenthSubStringException();
    }

    int i;
    int j = 0;
    //char pom;
    char* pomString =  new char [m];
    // pom = substr[j];
    if(n < m)
    {
        delete [] pomString;
        return 0;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            if(substr[j] == this->stringValue[i])
            {
                pomString[j] = substr[j];
                j++;
                if(j >= m)
                {
                    int comp = strcmp(substr, pomString);
                    if(comp == 0)
                    {
                        delete [] pomString;
                        return 1;
                    }
                }
            }
        }
        delete [] pomString;
        return 0;
    }
}

MyString MyString::append(int pos, char* str)
{
    if (str == nullptr && this->stringValue)
    {
    throw NullPointerException();
    }

    int n = strlen(this->stringValue);
    int m = strlen(str);
    MyString newStr = new char [m + n];
    int i = 0;
    int j = 0;
    int k = 0;

    if(pos <= n)
    {
        while(i < m + n && k < n)
        {
            if(k == pos)
            {
                for(j = 0; j < m; j++)
                {
                    newStr.stringValue[i] = str[j];
                    i++;
                }
            }
            newStr.stringValue[i] = this->stringValue[k];
            i++;
            k++;
        }
        newStr.stringValue[m + n] = '\0';
    }
    else
    {
        throw NotPositionInStringException();
    }
    return newStr.stringValue;
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
