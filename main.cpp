#include <iostream>
#include <exception>
#include "my_string.h"
#include "exception.h"
#include <string.h>
using namespace std;
using namespace my_string;

int main()
{
    int pos = 3;
    int len = 3;
    char* n;
    char str[] = {"str"};
    cout << str << " je str" <<endl;
    char str1[] = {"aaaaa"};
    cout << str1 << " je str1" <<endl;
    char str2[] = {"karamele"};
    cout << str2 << " je str2 " <<endl;
    MyString a("mmmmmm");
    cout << a << " je a" <<endl;
    MyString j("mmmmmm");
    cout << j << " je j" <<endl;
    if (a == a)
    {
        cout << " true" <<endl;
    }
    else
    {
        cout << " false" <<endl;
    }

    cout << " unesi tvoj string n: " << endl;
    cin >> n ;
    cout << n << " n je" << endl;

    try
    {

        MyString b(str2);
        cout << b << " je b" <<endl;
        b.isSubstring(str);
        cout << b << " b.isSubstring(str)" <<endl;

        MyString c(b);
        cout << c << endl;
        MyString d = c;
        cout << d << " je d" <<endl;
        MyString e = a + b;
        cout << e << " je e" <<endl;
        d = e + b;
        cout << d << " d = e + b" << endl;

        a.cat(str1);
        cout << a << " a.cat(str1)" << endl;
        e.cat(str);
        cout << e << " e.cat(str)" << endl;

        a.substring(pos, len);
        cout << a << " a.substring(5, 3)" << endl;
        a.substring(3, 5);
        cout << a << " je  a.substring(3, 5)" <<endl;

        bool IsSubStr = d.isSubstring(str);
        cout << IsSubStr<<" d.isSubstring(str)" <<endl;

        cout << e <<endl;
        e.append(3, str1);
        cout << e << "  e.append(3, str1)" <<endl;
    }

    catch(my_base_exception& ex)
    {
        cout << ex.what() << endl;
    }

    catch(NullPointerException& ex)
    {
        cout << ex.what() << endl;
    }

    catch (NegativeArgumentException ex)
    {
        cout << ex.what() << endl;
    }

    catch (InvalidArgumentException ex)
    {
        cout << ex.what() << endl;
    }

    catch (NotCorrectLenthSubStringException ex)
    {
        cout << ex.what() <<endl;
    }

    catch (NotPositionInStringException ex)
    {
        cout << ex.what() <<endl;
    }

    catch(exception& ex)
    {
        cout << "Uncaught occured!" << endl;
    }

    return 0;

}
