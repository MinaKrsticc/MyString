#include <iostream>
#include <exception>
#include "my_string.h"
#include "exception.h"
#include "Iterator.h"
#include <string.h>
#include <vector>
#include <iterator>

using namespace std;
using namespace my_string;

int main()
{
    MyString n;
    char str[] = {"str"};
    cout << str << " je str" <<endl;
    char str1[] = {"karamele"};
    cout << str1 << " je str1" <<endl;
    char str2[] = {"aleksa"};
    cout << str2 << " je str2 " <<endl;
    MyString a("aleksandar");
    cout << a << " je a" <<endl;
    MyString j("mmmmmm");
    cout << j << " je j" <<endl;
    MyString b(str2);
    MyString str3("Neki string");

    for( auto i = str3.begin(); i != str3.end(); i++)
    {
      std::cout << (*i)[0] << " OVO "<< std::endl;
    }

    if (a == b)
    {
        cout << " true" <<endl;
    }
    else
    {
        cout << " false" <<endl;
    }

   /* cout << " unesi tvoj string n: " << endl;
    cin >> n ;
    cout << n << " n je" << endl; */
    try
    {
        cout << b << " je b" <<endl;
        cout << b.isSubstring(str) << " b.isSubstring(str)" <<endl;

        MyString c(b);
        cout << c << endl;
        MyString p = c;
        cout << p << " je p" <<endl;
        MyString e = a + b;
        cout << e << " je e" <<endl;
        MyString d("hahahah");
        cout << d << endl;
        d = e + b;
        cout << d << " d = e + b" << endl;

        a.cat(str1);
        cout << a << " a.cat(str1)" << endl;
        e.cat(str);
        cout << e << " e.cat(str)" << endl;

        MyString x = a.substring(3,2);
        //MyString y;
        //y = a.substring(3, 2);
        cout << x << " je x{a.substring(3,2)};" <<endl;
        char pom[] = {"aleksa"};
        cout << d.isSubstring(pom) <<" d.isSubstring(str)" <<endl;

        cout << "je e " << e <<endl;
        cout << "je x " << x <<endl;

        x = e.append(3, str1);
        cout << x << " je x = e.append(3, str1)" <<endl;

        x = e.append1(2, str1);
        cout << x << " je x = e.append1(3, str1)" <<endl;

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

    catch (WrongArgumentException ex)
    {
        cout << ex.what() <<endl;
    }

    catch(exception& ex)
    {
        cout << "Uncaught occured!" << endl;
    }

    return 0;

}
