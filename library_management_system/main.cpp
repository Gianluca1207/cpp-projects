#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include "classes.hpp"

using namespace std;

int main() {

    cout << "Welcome to the Library Management System! \n";
    Library lib;
    int choice = 0;

    do {

        cout << "1. Add a book" << endl;
        cout << "2. Display all books" << endl;
        cout << "3. Search for a book" << endl;
        cout << "4. Display total number of books" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1 : {
            std::string title, author;
            int isbn, year;

            cout << "Enter book details \n";
            cout << "Title: ";
            std::cin.ignore();   //// ignore newline character from previous (different: std::cin) input
            std::getline(std::cin, title);

            cout << "Author: "; 
            std::getline(std::cin, author);

            cout << "ISBN: ";
            std::cin >> isbn;
            std::cin.ignore();   //// ignore newline character from previous (different: std::cin) input

            cout << "Year of Publication: ";
            std::cin.ignore();   //// ignore newline character from previous (different: std::cin) input
            std::cin >> year;

            Book book1(title, author, isbn, year);
            lib.addBook(book1);

            break;
        }

        case 2 : {
            lib.display_Books();
            break;
        }

        case 3 : {
            std::string searchTerm;
            cout << "Enter search term (title or author) : ";
            std::cin.ignore();
            std::getline (std::cin, searchTerm);
            lib.searchBook(searchTerm);      // make sure to type lib.searchBook and not only searchBook !!
            break;
        }

        case 4: {
            lib.DisplayTotalNumber() ;
            break;
        }

        case 5: {
            break;
        }

        default:
            break;
        }

    }
    while (choice != 5);
}
