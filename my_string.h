#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
using namespace std;

namespace my_string {

class MyString{
private:
    char *stringValue;
    int stringcmp(char* a, char*b);
    char* getStringValue();
    void setStringValue(char* newStringValue);

public:
    MyString();
    MyString(const MyString&);//konstruktor kopije
    MyString(const char* newString);
    ~MyString();//destruktor

    int length(MyString& rhs);
    int len();
    void cat(char* newString);
    bool isSubstring(char* str, char* substr);
    MyString substring(int pos, int length);

    friend istream& operator>>(istream& in, const MyString& str);
    friend ostream& operator<<(ostream& out, const MyString& str);
    bool operator==(const MyString& rhs);
    MyString operator+(const MyString& rhs);

};

}

#endif // MY_STRING_H
