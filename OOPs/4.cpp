#include <iostream>
using namespace std;
struct extraInfo
{
    int rating;
    string region;
};
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
    return 0;
}