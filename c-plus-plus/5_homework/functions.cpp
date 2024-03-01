#include "functions.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void load_files(Library &MyLibrary){
    fstream file;
    string files[3] = {"data_files/fantasy.txt", "data_files/scifi.txt", "data_files/programming.txt"};
    string genres[3] = {"Fantasy", "Science Fiction", "Programming"};
    for (int i = 0; i < 3; i++){
        file.open(files[i], ios::in);
        int j=0;
        string entry[4];
        while (getline(file, entry[j])) {
        j++;
        if(j == 4){
            j = 0;
            Book book;
            book.title = entry[0];
            book.author = entry[1];
            book.releaseYear = stoi(entry[2]);
            book.ISBN = entry[3];
            MyLibrary.Shelves.at(i).Books.push_back(book);
            MyLibrary.Shelves.at(i).genre = genres[i];
        }   
        }
        file.close();
    }
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


void switch_checked_out_status(Book &book){
    if(book.checkedOut)
        book.checkedOut = false;
    else
        book.checkedOut = true;
}

void list_shelf(Shelf &shelf){
    
    for (int i = 0; i <  shelf.Books.size(); i++){
        cout << endl << i + 1 << ". Book:";
        string temp;
        (shelf.Books.at(i).checkedOut) ? temp = "X_" : temp = "";
        cout << "\nTitle: " << temp << shelf.Books.at(i).title;
        cout << "\nAuthor: " << shelf.Books.at(i).author;
        cout << "\nYear of release: " << shelf.Books.at(i).releaseYear;
        cout << "\nISBN: " << shelf.Books.at(i).ISBN;
        string isValid;
        (is_ISBN_valid(shelf.Books.at(i).ISBN)) ? isValid = "valid." : isValid = "not valid.";
        cout << "\nISBN is " << isValid;
        cout << "\n----------------------------------------------------------------------------------------------------------";
    }
}