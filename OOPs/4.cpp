#include <iostream>
using namespace std;
// IN c language , struct cannot have functions the can have function poiniter which is very different from member function . But in C++ YOU can have member function inside the struct as well . Difference between struct and classes is: struct by default is having public member functions and variables whereas classes have private access. And also inheritance is possible in c++ structures and classes both. But in c language its not possible .Because oops part is just added in c++.
// Classes is normally used for data abstraction and further inheritance.	Struct is normally used for the grouping of data

/* Union:
we define union similar to struct but the major difference between struct and union is :
1. union store all data members at same location while struct asssgin diff memory to every data members.
2. So struct object size will be sum of all data members size and union object size will be largest of all data members.
3. Only one data member can be initialised/accessed at one time in union whereas struct can intialise/accessed every data members at the same time:
// declaring structure
struct struct_example
{
    int integer;
    float decimal;
    char name[20];
};

// declaring union

union union_example
{
    int integer;
    float decimal;
    char name[20];
};
    struct struct_example s={18,38,"geeksforgeeks"};
    union union_example u={18,38,"geeksforgeeks"};
        printf("structure data:\n integer: %d\n"
                "decimal: %.2f\n name: %s\n",
                s.integer, s.decimal, s.name);
    printf("\nunion data:\n integer: %d\n"
                 "decimal: %.2f\n name: %s\n",
                u.integer, u.decimal, u.name);

    Result:
    structure data:
 integer: 18
 decimal: 38.00
 name: geeksforgeeks

union data:
 integer: 18
 decimal: 0.00
 name: ?




*/

struct extraInfo
{
    int rating;
    string region;
    void func();
};
void extraInfo::func()
{
    cout << "HELLO" << endl;
}
struct movies_t
{
    string title;
    int year;
    extraInfo info;
};
struct friends_t
{
    string name;
    string email;
    movies_t favourite_movie;
} charlie, maria;

int main()
{
    charlie.name = "John";
    charlie.favourite_movie.title = "Shiddat";
    charlie.favourite_movie.year = 2017;
    charlie.favourite_movie.info.rating = 5;
    extraInfo a;
    a.func();
    return 0;
}