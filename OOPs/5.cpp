#include <iostream>
using namespace std;
struct stock
{
    int available;
    int cost;
};
struct books
{
    string title;
    string author;
    int price;
    string publisher;
    stock position;
};
int main()
{
    books list_of_books[5] = {
        {
            title : "The 7 habits of the successfull people",
            author : "Stephen convey",
            price : 700,
            publisher : "James",
            position : {
                available : 10,
                cost : 2000
            }
        },
        {
            title : "The 7 habits of the successfull people",
            author : "Stephen convey",
            price : 700,
            publisher : "James",
            position : {
                available : 10,
                cost : 2000
            }
        },
        {
            title : "The 7 habits of the successfull people",
            author : "Stephen convey",
            price : 700,
            publisher : "James",
            position : {
                available : 10,
                cost : 2000
            }
        },
        {
            title : "The 7 habits of the successfull people",
            author : "Stephen convey",
            price : 700,
            publisher : "James",
            position : {
                available : 10,
                cost : 2000
            }
        },
        {
            title : "The 7 habits of the successfull people",
            author : "Stephen convey",
            price : 700,
            publisher : "James",
            position : {
                available : 10,
                cost : 2000
            }
        },
    };
    char searched_title[120];
    char searched_author[120];
    cout << "Enter the title of the book you want to buy " << endl;
    cin.getline(searched_author, 120);
    cout << "Enter the author of the book you want to buy " << endl;
    cin.getline(searched_author, 120);
    int no_of_copies;
    for (int i = 0; i < 5; i++)
    {
        cout << searched_title << " " << searched_title << endl;
        if (list_of_books[i].title == searched_title && list_of_books[i].author == searched_author)
        {
            cout << "Book found" << endl;
            cout << "Book details : " << endl;
            cout << "Title" << list_of_books[i].title << endl;
            cout << "Author" << list_of_books[i].author << endl;
            cout << "Price" << list_of_books[i].price << endl;
            cout << "Publisher" << list_of_books[i].publisher << endl;
            cout << "Enter the no. of copies you want " << endl;
            cin >> no_of_copies;
            if (no_of_copies <= list_of_books[i].position.available)
            {
                list_of_books[i].position.available -= no_of_copies;
                cout << "Cost of books " << no_of_copies * list_of_books[i].position.cost << endl;
            }
            else
            {
                cout << "Required no of Copies are not available in the stock. Available stock: " << list_of_books[i].position.available << endl;
            }
            break;
        }
        else
        {
            cout << "Book details are not correct" << endl;
            break;
        }
    }

    return 0;
}