#include <iostream>
#include <string.h>
using namespace std;
class str
{
    char *p;
    int len;

public:
    str()
    {
        len = 0;
        p = 0; // we are making p pointer here nulll pointer and on deferencing nulll pointer gives segmentation fault
        cout << "Default constructor" << endl;
    }
    str(char *t)
    {
        len = strlen(t);
        p = new char[len + 1];
        // p = t; //p points to t and p and in this p points to address of t
        strcpy(p, t); // t just copied to p and their addresses will be different
        cout << "Dynamic constructor" << endl;
    }
    str(const str &s)
    {
        len = s.len;
        p = new char[len + 1]; // dynamically creating char array which is created in heap and we have to flush its memory also in destructor
        strcpy(p, s.p);
        cout << "Copy constructor" << endl;
    }
    ~str()
    {
        delete p;
    }
    void printStr()
    {
        cout << "\nThe string is::::>>" << p << endl;
    }
    friend str operator+(const str &s1, const str &s2);
    friend int operator<=(const str &s1, const str &s2);
};
str operator+(const str &s1, const str &s2)
{
    str temp;
    temp.len = s1.len + s2.len;
    temp.p = new char[temp.len + 2];
    strcpy(temp.p, s1.p);
    strcat(temp.p, " ");
    strcat(temp.p, s2.p);
    return temp;
}
int operator<=(const str &s1, const str &s2)
{
    if (s1.len <= s2.len)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char a[] = "Hello!!";
    char b[] = "Hii!";
    // char *c="jee"; //shows warinig because of old and new ccompliler
    char d[5] = {'a', 'b', 'c'};
    char *s = a; // call dynamic constructor
    char *t = b;

    str s1(s), s2(t);
    str s3(s1);       // copy constructor
    str s4 = s1 + s2; // default constructor
    s4.printStr();
    cout << (s1 <= s2) << endl;

    str sa("C PLus Plus"); // dynamic constructor
    str sb("Kirti");

    str s5 = sa + sb; // default constructor
    s5.printStr();
    return 0;
}