
#include <iostream>
#include "classes.hpp"

using namespace std;

Book::Book (std::string new_Title, std::string new_Author, int new_ISBN, int new_Year_of_Publication) : 
        Title (new_Title), Author (new_Author), ISBN (new_ISBN), Year_of_Publication (new_Year_of_Publication) {}      // definition of constructor
                                                                                      

void Library::addBook (Book book) {           // make sure to add the return type here too !!
    books.push_back (book);                //using the push_back method for vectors
}

void Library::display_Books() {
    for (const Book& book: books) {     // using the & symbol  avoids making a copy of each Book object during each iteration of the loop
        std::cout << book.get_Title() << endl;        //make sure to add () for each method
        std::cout << book.get_Author() << endl;
        std::cout << book.get_ISBN() << endl;
        std::cout << book.get_Year() << endl;
    }
}

void Library::searchBook (std::string searchTerm) {
    for (const Book& book : books) {           // using the & symbol  avoids making a copy of each Book object during each iteration of the loop
        if (book.get_Author() == searchTerm || book.get_Title() == searchTerm) {
            std::cout << book.get_Title() << endl;        
            std::cout << book.get_Author() << endl;       // print all book details (we can't use the DisplayBooks method because it would show the whole library of
            std::cout << book.get_ISBN() << endl;         // books !! )
            std::cout << book.get_Year() << endl;
        }
    }
}

void Library::DisplayTotalNumber () {
    //for (int i=0; i < books.size(); i++)    using a for loop is unnecessary

    std::cout << "Total number of books in the library: " << books.size() << endl;     // I use the size method, because books is a vector and not an array
}