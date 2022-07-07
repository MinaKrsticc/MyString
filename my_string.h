#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
using namespace std;

namespace my_string {

class MyString{
private:
    char *stringValue;
public:
    MyString();
    MyString(const MyString&);//konstruktor kopije
    MyString(char* newString);
    ~MyString();//destruktor
    char* getStringValue();
    void setStringValue(char* newStringValue);
    int length(MyString& rhs);
    void cat(char* newString);
    MyString substring(int pos, int length);

    istream& operator>>(istream& in);
    ostream& operator<<(ostream& out);
    bool operator==(const MyString& rhs);
    MyString operator+(const MyString& rhs);

};
}

#endif // MY_STRING_H
