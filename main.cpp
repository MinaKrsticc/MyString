#include <iostream>
#include "my_string.h"
#include <string.h>
using namespace std;
using namespace my_string;

int main()
{
    MyString a("jshd");
    cout << a << " prvi" <<endl;

    char str[] = {"nekaVrednost"};
    char str1[] = {"lallal"};
    //int n = a.length(str);
    // int pos = 2;
    // int len = 3;

    MyString b(str);
    cout << b << " je b" <<endl;
    cout << a.len() << endl;
    MyString c(b);

    cout << c << endl;
    MyString d = c;
    MyString e = a + b;

    cout << e << " je e" <<endl;
    d = a + b;
    cout << d << " d = a + b" << endl;

    a.cat(str1);
    cout << a << " a.cat(str1)" << endl;
    e.cat(str);
    cout << e << " e.cat(str)" << endl;

    c = a.substring(0,3);
    cout << c << " c = a.substring(0,3)" << endl;
    MyString g = a.substring(0,5);
    cout << g << " je g" <<endl;

    //a.cat(b);
    //a.substring(pos, len);
    return 0;

}
