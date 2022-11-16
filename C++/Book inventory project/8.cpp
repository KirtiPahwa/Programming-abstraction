#include <iostream>
#include <fstream>
#include <vector>
#define MAX_LENGTH 1000
using namespace std;
class Stock
{
public:
    int available_copies;
};
class Book
{
private:
    Stock position;
    static int bookCount;

public:
    /* data members */
    char author[MAX_LENGTH];
    char publisher[MAX_LENGTH];
    char title[MAX_LENGTH];
    int price;

    /* Prototype of constructor and destructor */
    Book();
    ~Book();

    /* Prototypes of methods */
    void setPosition(int);
    int getPosition();
    bool stockAvailable(int);
    void setDetails();
    void setBookCount(int);
    int getBookCount();
    void buyBooks(int);
};

/*static variabl*/

int Book::bookCount = 0;

Book::Book()
{
    /*constructor*/
}

/* declaration of methods*/

void Book::buyBooks(int copies)
{
    this->position.available_copies -= copies;
}

void Book::setPosition(int position)
{
    this->position.available_copies = position;
}

void Book::setDetails()
{
    cout << "Enter the Author name of the Book: " << endl;
    cin.ignore();
    cin.getline(author, MAX_LENGTH);
    cout << "Enter the Publisher name of the Book:" << endl;
    cin.getline(publisher, MAX_LENGTH);
    cout << "Enter the Title of the Book:" << endl;
    cin.getline(title, MAX_LENGTH);
    cout << "Enter the price of 1 copy of Book: " << endl;
    cin >> price;
    int position;
    cout << "Enter the no. of copies of the Book you want to add in stock" << endl;
    cin >> position;
    setPosition(position);
    cout << endl;
}

bool Book::stockAvailable(int a)
{
    if (this->position.available_copies >= (a))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Book::setBookCount(int a)
{
    bookCount = a;
}

int Book::getBookCount()
{
    return bookCount;
}

int Book::getPosition()
{
    return this->position.available_copies;
}

Book::~Book()
{
    /* destructor*/
}

void addBookIntoTheStock()
{
    ofstream fout;
    fout.open("BookList.txt", ofstream::binary | ios::app);
    int books = 1;
    int insert;
    Book b;
    cout << "Enter the no. of books you want to add in the stock" << endl;
    cin >> insert;
    while (insert--)
    {
        /* inserting all the data from console to the BookList file */
        cout << "Enter the details for the Book " << books++ << ":" << endl;
        b.setDetails();
        fout.write((char *)&b, sizeof(b));
    }

    cin.ignore();
    b.setBookCount(books);
    fout.close();

    cout << "Books added in the Stock!!" << endl;
    cout << endl;
}
void printDetailsOfTheBooks()
{
    vector<Book> books;
    ifstream fin;
    fin.open("BookList.txt", ifstream::binary);
    if (fin.is_open())
    {
        Book b;

        /* inserting all the data from file to vector of Book class */

        while (!fin.eof())
        {
            fin.read((char *)&b, sizeof(b));
            books.push_back(b);
        }
        fin.close();

        /* Printing the data from the vector */

        cout << "Details of the books: " << endl;
        for (int j = 0; j < books.size() - 1; j++)
        {
            cout << "Book No: " << j + 1 << endl;
            cout << "Author Name: " << books[j].author << endl;
            cout << "Publisher Name: " << books[j].publisher << endl;
            cout << "Title: " << books[j].title << endl;
            cout << "Price: " << books[j].price << endl;
            cout << "Available Copies: " << books[j].getPosition() << endl;
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "ERROR: File does not exist. So first add some books into the file using addBookIntoTheStock() function " << endl;
    }
}
void searchAndBuy()
{
    vector<Book> books;
    ifstream fin;
    fin.open("BookList.txt", ifstream::binary);
    if (fin.is_open())
    {

        Book b;
        int count = 0;
        while (!fin.eof())
        {
            /* inserting all the data from file to vector of Book class */
            fin.read((char *)&b, sizeof(b));
            books.push_back(b);
            count++;
        }

        int a = 1;
        while (a == 1)
        {
            string title, author;
            cout << "Enter the title of the book you want to buy: " << endl;
            getline(cin, title);
            cout << "Enter the author name of the book you want to buy: " << endl;
            getline(cin, author);
            int copies;
            bool flag = false;

            /* searching the require title and author from the vector of Book class */
            for (int i = 0; i < books.size(); i++)
            {

                if (books[i].title == title && books[i].author == author)
                {
                    cout << "BOOK FOUND!!!" << endl;
                    cout << "How many copies you want to buy? " << endl;
                    cin >> copies;
                    flag = true;
                    if (books[i].stockAvailable(copies))
                    {
                        books[i].buyBooks(copies);
                        cout << endl;
                        cout << "Details of the searched Book:- " << endl;
                        cout << "Author Name: " << books[i].author << endl;
                        cout << "Publisher Name: " << books[i].publisher << endl;
                        cout << "Title: " << books[i].title << endl;
                        cout << "Price of 1 copy of the book: " << books[i].price << endl;
                        cout << "Cost of " << copies << " copies of the book is : " << books[i].price * copies << endl;
                    }
                    else
                    {
                        cout << "Stock not available" << endl;
                    }
                    break;
                }
            }
            if (!flag)
            {
                cout << "BOOK WITH THE FILLED DETAILS NOT FOUND!!!" << endl;
            }
            cout << endl;
            cout << "Enter :" << endl;
            cout << "1 - For buying/searching more books " << endl;
            cout << "0 - For no further search" << endl;
            cin >> a;
            cin.ignore();
            if (a != 1)
            {
                break;
            }
        }
    }
    else
    {
        cout << "ERROR: File does not exist. So first add some books into the file using addBookIntoTheStock() function " << endl;
    }
}
int main()
{
    addBookIntoTheStock();    // for adding books in the 'BookList.txt' file
    printDetailsOfTheBooks(); // for printing the details of all the books
    searchAndBuy();           // for searching the book with title and author name and get the cost and details of the searched book

    return 0;
}

/*
Important Points:-
1.When cin.getline() reads from the input, there is a newline character left in the input stream, so it doesn't read your c-string. Use cin.ignore() before calling getline().
2. we cann't use string  because- A std::string (or any other dynamic sized container) contains a pointer to its character data that is stored elsewhere in memory. If you were to read()/write() the std::string itself as-is, you would only be reading/writing the pointer value, not the actual character data. This is not the case with a fixed array.



*/
