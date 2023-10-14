#include "functions.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    
    Library MyLibrary;

    // Loading initial shelves and books
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
        cout << "\n     3. Add genre";
        cout << "\n     4. Add book";
        cout << "\n     5. Exit";
        cout << "\n----------------------------------------------------------------------------------------------------------";
        cout << "\n     Choose option: ";
        cin >> t;

        if (t == 1){
            system("cls");
            for (int i = 0; i < MyLibrary.Shelves.size(); i++){
                cout << endl << MyLibrary.Shelves.at(i).genre;
                cout << "\n----------------------------------------------------------------------------------------------------------";
                list_shelf(MyLibrary.Shelves.at(i));
                cout << "\n----------------------------------------------------------------------------------------------------------";
                cout << "\n----------------------------------------------------------------------------------------------------------";
            }
            system("pause");
        }
        
        if (t == 2){
            system("cls");
            int counter = 1;
            cout << "\n----------------------------------------------------------------------------------------------------------";
            for (int i = 0; i < MyLibrary.Shelves.size(); i++){
                cout << "\n     " << i + 1 << ". " << MyLibrary.Shelves.at(i).genre;
                counter++;
            }
            cout << "\n     " << counter <<". Exit";
            cout << "\n----------------------------------------------------------------------------------------------------------";
            cout << "\n     Choose genre: ";
            int genre;
            cin >> genre;
            if (genre < counter){
                system("cls");
                list_shelf(MyLibrary.Shelves.at(genre - 1));                
                system("pause");

                cout << "\n----------------------------------------------------------------------------------------------------------";
                cout << "\n     1. Borrow book";
                cout << "\n     2. Return book";
                cout << "\n     3. Go back";
                cout << "\n----------------------------------------------------------------------------------------------------------";
                cout << "\n     Choose option and No. of book (option No.): ";
                int option, noBook;
                cin >> option;

                switch (option){
                case (1):
                    cin >> noBook;
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
                    cin >> noBook;
                    if (checked_out(MyLibrary.Shelves.at(genre-1).Books.at(noBook-1))){
                        switch_checked_out_status(MyLibrary.Shelves.at(genre-1).Books.at(noBook-1));
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
        }

        if (t == 3){
            cout << "Enter new genre name: ";
            string genre;
            cin.ignore();
            getline(cin, genre);

            cout << "You have to asign a book to new genre: " << endl;
            string title, author, ISBN;
            int releaseYear;
            cout << "Enter book's title: ";
            getline(cin, title);
            cout << "Enter book's author: ";
            getline(cin, author);
            cout << "Enter book's year of release: ";
            cin >> releaseYear;
            cout << "Enter book's ISBN-13: ";
            cin >> ISBN;

            vector<Book> new_book;

            new_book.push_back({title, author, releaseYear, ISBN});

            MyLibrary.Shelves.push_back({new_book, genre});
        }

        if (t == 4){
            system("cls");
            int counter = 1;
            cout << "\n----------------------------------------------------------------------------------------------------------";
            for (int i = 0; i < MyLibrary.Shelves.size(); i++){
                cout << "\n     " << i + 1 << ". " << MyLibrary.Shelves.at(i).genre;
                counter++;
            }
            cout << "\n     " << counter <<". Exit";
            cout << "\n----------------------------------------------------------------------------------------------------------";
            cout << "\n     Choose genre of your new book: ";
            int genre;
            cin >> genre;

            if (genre < counter){
                system("cls");
                cout << "Enter book's properties: " << endl;
                string title, author, ISBN;
                int releaseYear;
                cout << "Enter book's title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book's author: ";
                getline(cin, author);
                cout << "Enter book's year of release: ";
                cin >> releaseYear;
                cout << "Enter book's ISBN-13: ";
                cin >> ISBN;

                MyLibrary.Shelves.at(genre-1).Books.push_back({title, author, releaseYear, ISBN});
            }
        }

        if (t == 5){
            break;
        }
    }

    return 0;
}