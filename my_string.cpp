namespace my_string {

class MyString{
public:
    MyString(){};
    MyString(const MyString&){};//konstruktor kopije
    MyString(char*){};
    ~MyString(){};
};

MyString CopyString(MyString elementToBeCoped)
{
    MyString elementInWhichCoped = elementToBeCoped;
    return elementInWhichCoped;
}

};
