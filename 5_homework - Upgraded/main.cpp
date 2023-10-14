#include "functions.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

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