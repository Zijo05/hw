#include <iostream>
#include <vector>
#include <fstream>

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
};

struct Library
{
    vector<Shelf> Shelves;
};


void load_files(Library &MyLibrary){
    fstream file;
    file.open("fantasy.txt", ios::in);
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
        }
    }
    file.close();

    file.open("scifi.txt", ios::in);
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
        }
    }
    file.close();

    file.open("programming.txt", ios::in);
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

int main() {
    
    Library MyLibrary;

    Shelf Fantasy, SciFi, Programming;

    MyLibrary.Shelves.push_back(Fantasy);
    MyLibrary.Shelves.push_back(SciFi);
    MyLibrary.Shelves.push_back(Programming);

    load_files(MyLibrary);

    while(1){
        system("cls");
        int t;
        cout << "\n----------------------------------------------------------------------------------------------------------";
        cout << "\n     1. List all books";
        cout << "\n     2. Return/borrow book";
        cout << "\n     3. Exit";
        cout << "\n----------------------------------------------------------------------------------------------------------";
        cout << "\n     Choose option: ";
        cin >> t;

        if (t == 1){
            system("cls");
            cout << "Fantasy books: ";
            list_shelf(MyLibrary.Shelves.at(0));
            cout << "\n----------------------------------------------------------------------------------------------------------";
            cout << "\n----------------------------------------------------------------------------------------------------------";
            cout << "\nScience fiction books: ";
            list_shelf(MyLibrary.Shelves.at(1));
            cout << "\n----------------------------------------------------------------------------------------------------------";
            cout << "\n----------------------------------------------------------------------------------------------------------";
            cout << "\nProgramming books: ";
            list_shelf(MyLibrary.Shelves.at(2));
            system("pause");
        }
        
        if (t == 2){
            system("cls");
            cout << "\n----------------------------------------------------------------------------------------------------------";
            cout << "\n     1. Fantasy";
            cout << "\n     2. Science fiction";
            cout << "\n     3. Programming";
            cout << "\n     4. Exit";
            cout << "\n----------------------------------------------------------------------------------------------------------";
            cout << "\n     Choose genre: ";
            int genre;
            cin >> genre;

            system("cls");
            switch (genre) {
            case (1):
                list_shelf(MyLibrary.Shelves.at(0));
                break;
            case (2):
                list_shelf(MyLibrary.Shelves.at(1));
                break;
            case (3):
                list_shelf(MyLibrary.Shelves.at(2));
                break;
            default:
                break;
            }

            cout << "\n----------------------------------------------------------------------------------------------------------";
            cout << "\n     1. Borrow book";
            cout << "\n     2. Return book";
            cout << "\n     3. Go back";
            cout << "\n----------------------------------------------------------------------------------------------------------";
            cout << "\n     Choose option and No. of book (option No.): ";
            int option, noBook;
            cin >> option >> noBook;

            switch (option){
            case (1):
                if (checked_out(MyLibrary.Shelves.at(genre-1).Books.at(noBook-1))){
                    system("cls");
                    cout << "Book already borrowed." << endl;
                    system("pause");
                }
                else {
                    switch_checked_out_status(MyLibrary.Shelves.at(genre-1).Books.at(noBook-1));
                    system("cls");
                    cout << "Book successfully borrowed." << endl;
                    system("pause");
                }
                break;
            case (2):
                if (checked_out(MyLibrary.Shelves.at(genre-1).Books.at(noBook-1))){
                    system("cls");
                    cout << "Book successfully returned." << endl;
                    system("pause");
                }
                else {
                    switch_checked_out_status(MyLibrary.Shelves.at(genre-1).Books.at(noBook-1));
                    system("cls");
                    cout << "Book already returned." << endl;
                    system("pause");
                }
                break;
            default:
                break;
            }
        }

        else{
            break;
        }
    }
    


    return 0;
}