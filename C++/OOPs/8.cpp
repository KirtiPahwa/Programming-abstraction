#include <iostream>
using namespace std;
class stock
{
public:
    int available_copies;
    bool buyCopies(int copies)
    {

        if (copies <= available_copies)
        {
            cout << "Stock  available" << endl;
            available_copies -= copies;
            return 1;
        }
        else
        {
            cout << "Stock not available" << endl;
            return 0;
        }
    }
};
class book
{
private:
    static int objectCount;
    stock position;

public:
    string author;
    string publisher;
    string title;
    int price;
    book();
    book(string a, string p, string t, int price = 0)
    {
        objectCount++;
        cout << objectCount << endl;
        cout << "Original Book created" << endl;
        author = a;
        publisher = p;
        title = t;
        this->price = price;
    }
    ~book() // destructor
    {
        cout << "Destructor function called" << endl;
    }
    void setPosition(int);
    void checkStock(int);
};
int book::objectCount;
book::book()
{
    cout << "Demo book created" << endl;
}

void book::setPosition(int a)
{
    position.available_copies = a;
}
void book::checkStock(int a)
{
    if (position.buyCopies(a))
    {
        cout << "Cost of the books: " << price * a << endl;
    }
}
void search(book a[], int no_of_books)
{
    char title[120], author[120];
    cout << "Enter the title of the book you want to buy" << endl;
    cin.getline(title, 120);
    cout << "Enter the author of the book you want to buy" << endl;
    cin.getline(author, 120);
    int c;
    bool flag = false;
    for (int i = 0; i < no_of_books; i++)
    {
        if (a[i].title == title && a[i].author == author)
        {
            cout << "BOOK FOUND" << endl;
            cout << "How many copies you want to buy? " << endl;
            cin >> c;
            flag = true;
            a[i].checkStock(c);
            break;
        }
    }
    if (!flag)
    {
        cout << "BOOK NOT FOUND" << endl;
    }
}
void printAddress(book b)
{
    cout << "Address of :" << endl;
    cout << "Title " << &(b.title) << endl;
    cout << "Author " << &(b.author) << endl;
}
int main()
{
    int no_of_books = 1;
    book a[1];
    cout << "Main function called" << endl;
    a[0] = book("Stephen", "James", "The 7 habits of successfull people", 230);
    a[0].setPosition(7);
    printAddress(a[0]);
    book *b = new book("Stephen2", "James", "The 7 habits of successfull people", 230); // pointer object of class
    cout << b->author << endl;                                                          // both  are equivalent --- b->author and (*b).author
    cout << (*b).author << endl;
    printAddress(*b);

    cout << "Size of pointer to Book Object " << sizeof(b) << endl; // size of the pointer object is 8 bytes (64 bit compiler)
    search(a, no_of_books);
    // delete (a);
    delete b;
    return 0;
}