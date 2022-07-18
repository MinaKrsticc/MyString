#include <iostream>
#include <exception>
#include "my_string.h"
#include "exception.h"
#include <string.h>
using namespace std;
using namespace my_string;

int main()
{
    MyString a("mmmmmm");
    cout << a << " je a" <<endl;
    int pos = 5;
    int len = 3;

    char str[] = {"str"};
    cout << str << " je str" <<endl;
    char str1[] = {"aaaaa"};
    cout << str1 << " je str1" <<endl;
    char str2[] = {"karamele"};
    cout << str2 << " je str2" <<endl;

    try
    {
        MyString b(str2);
        cout << b << " je b" <<endl;
        cout << b.isSubstring(str)<<" b.isSubstring(str)" <<endl;
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

        c = a.substring(pos, len);
        cout << c << " c = a.substring(5,3)" << endl;
        MyString g = a.substring(3,5);
        cout << g << " je g = a.substring(3,5)" <<endl;

        cout << d.isSubstring(str)<<" d.isSubstring(str)" <<endl;
        cout << e <<endl;
        MyString f = e.append(3, str1);
        cout << f <<" f = e.append(3, str1)" <<endl;

        //a.cat(b);
        //a.substring(pos, len);
    }

    catch(my_base_exception& ex)
    {
        cout << ex.what() << endl;
    }

    catch(NullPointerException& ex)
    {
        cout << ex.what() << endl;
    }

    catch(exception& ex)
    {
        cout << "Uncaught occured!" << endl;
    }

    catch (NegativeArgumentException ex)
    {
        cout << ex.what() << endl;
    }

    catch (NotCorrectPositionException ex)
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

    MyString b(str2);
    cout << b << " je b" <<endl;
    cout << b.isSubstring(str)<<" b.isSubstring(str)" <<endl;
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

    c = a.substring(pos, len);
    cout << c << " c = a.substring(5,3)" << endl;
    MyString g = a.substring(3,5);
    cout << g << " je g = a.substring(3,5)" <<endl;

    cout << d.isSubstring(str)<<" d.isSubstring(str)" <<endl;
    cout << e <<endl;
    MyString f = e.append(3, str1);
    cout << f <<" f = e.append(3, str1)" <<endl;

    //a.cat(b);
    //a.substring(pos, len);
    return 0;

}
