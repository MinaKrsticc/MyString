#ifndef ITERATOR_H
#define ITERATOR_H
#include "my_string.h"
using namespace std;
using namespace my_string;

struct MyStringIterator
{
private:

    MyString *m_ptr;

public:

    // Prefix increment
    MyStringIterator& operator++()
    {
        m_ptr++; return *this;
    };

    // Postfix increment
    MyStringIterator operator++(int)
    {
        MyStringIterator tmp = *this;
        ++(*this);
        return tmp;
    };

    friend bool operator== (const MyStringIterator& a, const MyStringIterator& b)
    {
        return a.m_ptr == b.m_ptr;
    };

    friend bool operator!= (const MyStringIterator& a, const MyStringIterator& b)
    {
        return a.m_ptr != b.m_ptr;
    };

    MyStringIterator begin()
    {
        return m_ptr[0];
    };

    MyStringIterator end()
    {
        return MyStringIterator(&m_ptr[strlen(m_ptr)]);
    };
};
#endif // ITERATOR_H
