#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
#include <exception>
using namespace std;

namespace my_string {

class MyString{
private:
    char *stringValue;
    //char* getStringValue();
    //void setStringValue(char* newStringValue);
    int stringcmp(char* a, char*b);

public:
    MyString();
    MyString(int len);
    MyString(const MyString&);//konstruktor kopije
    MyString(const char* newString);
    ~MyString();//destruktor

    int length(MyString& rhs);
    int len();
    void cat(char* newString);
    bool isSubstring(char* substr);
    void substring(int pos, int length);

    void append(int pos, char* str);

    friend istream& operator>>(istream& in, const MyString& str);
    friend ostream& operator<<(ostream& out, const MyString& str);
    bool operator==(const MyString& rhs);
    MyString operator+(const MyString& rhs);

};

}

#endif // MY_STRING_H
