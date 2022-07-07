#include <iostream>
#include "my_string.h"
#include <string.h>
using namespace std;
using namespace my_string;

int main()
{
    int pos = 2;
    int len = 3;
    char str[] = {"nekaVrednost"};
    MyString a;
    MyString b(str);
    MyString c(b);
    MyString d = c;
    d = a;
    MyString e =a + b;
    d = a + b;
    a.cat(str);
    cout << "Please enter the numerator part: ";
    a.substring(pos, len);
    return 0;

}
