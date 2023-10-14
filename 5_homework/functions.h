#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>

using namespace std;

struct Book
{
    string title;
    string author;
    int releaseYear;
    string ISBN;
};

struct Shelf
{
    vector<Book> Books;
    string genre;
};

struct Library
{
    vector<Shelf> Shelves;
};

void load_files(Library &MyLibrary);
bool is_ISBN_valid(string &isbn);
bool checked_out(Book &book);
void switch_checked_out_status(Book &book);
void list_shelf(Shelf &shelf);

#endif