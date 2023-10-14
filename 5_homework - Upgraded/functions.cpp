#include "functions.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void load_files(Library &MyLibrary){
    fstream file;
    file.open("data_files/fantasy.txt", ios::in);
    int i=0;
    string entry[4];
    while (getline(file, entry[i])) {
        i++;
        if(i == 4){
            i = 0;
            Book book;
            book.title = entry[0];
            book.author = entry[1];
            book.releaseYear = stoi(entry[2]);
            book.ISBN = entry[3];
            MyLibrary.Shelves.at(0).Books.push_back(book);
            MyLibrary.Shelves.at(0).genre = "Fantasy";
        }
    }
    file.close();

    file.open("data_files/scifi.txt", ios::in);
    while (getline(file, entry[i])) {
        i++;
        if(i == 4){
            i = 0;
            Book book;
            book.title = entry[0];
            book.author = entry[1];
            book.releaseYear = stoi(entry[2]);
            book.ISBN = entry[3];
            MyLibrary.Shelves.at(1).Books.push_back(book);
            MyLibrary.Shelves.at(1).genre = "Science Fictions";
        }
    }
    file.close();

    file.open("data_files/programming.txt", ios::in);
    while (getline(file, entry[i])) {
        i++;
        if(i == 4){
            i = 0;
            Book book;
            book.title = entry[0];
            book.author = entry[1];
            book.releaseYear = stoi(entry[2]);
            book.ISBN = entry[3];
            MyLibrary.Shelves.at(2).Books.push_back(book);
            MyLibrary.Shelves.at(2).genre = "Programming";
        }
    }
    file.close();

}


bool is_ISBN_valid(string &isbn) {
    if (isbn.size() != 13)
        return false;

    int sum = 0;

    // Are characters in ISBN all digits
    // Calculate sum of first 12 digits
    for (int i = 0; i < 12; i++) {
        if (isdigit(isbn[i])) {
            int digit = isbn[i] - '0';
            sum += (i % 2 == 0) ? digit : 3 * digit;
        } 
        
        else {
            return false;
        }
    }

    // Is last character of isb a digit
    // Is sum modulo 10 when subtracted from 10 equal to last digit of ISBN
    if (isdigit(isbn[12])) {
        int lastDigit = isbn[12] - '0';
        return (10 - (sum % 10)) == lastDigit;
    }

    return false;
}

bool checked_out(Book &book){
    if(book.title[0] == 'X' && book.title[1] == '_')
        return true;
    
    return false;
}

void switch_checked_out_status(Book &book){
    if(checked_out(book)){
        string temp;
        for (int i = 2; i < book.title.size(); i++){
            temp.push_back(book.title[i]);
        }

        book.title = temp;
    }

    else{
        string temp = "X_";
        for (int i = 0; i < book.title.size(); i++){
            temp.push_back(book.title[i]);
        }

        book.title = temp;
    }
}

void list_shelf(Shelf &shelf){
    
    for (int i = 0; i <  shelf.Books.size(); i++){
        cout << endl << i + 1 << ". Book:";
        cout << "\nTitle:" << shelf.Books.at(i).title;
        cout << "\nAuthor: " << shelf.Books.at(i).author;
        cout << "\nYear of release: " << shelf.Books.at(i).releaseYear;
        cout << "\nISBN: " << shelf.Books.at(i).ISBN;
        string isValid;
        (is_ISBN_valid(shelf.Books.at(i).ISBN)) ? isValid = "valid." : isValid = "not valid.";
        cout << "\nISBN is " << isValid;
        cout << "\n----------------------------------------------------------------------------------------------------------";
    }
}