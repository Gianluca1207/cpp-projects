#include <iostream>
#include <vector>
#include <string>

class Book {
    std::string Title;
    std::string Author;
    int ISBN;
    int Year_of_Publication;

    public:
        Book (std::string new_Title, std::string new_Author, int new_ISBN, int new_Year_of_Publication);     //declaration of constructor

    //getter methods
    std::string get_Title() const {           // Adding const to getter methods indicates that these methods do not modify the state of the object
        return Title;
    }

    std::string get_Author() const {         // Adding const to getter methods indicates that these methods do not modify the state of the object
        return Author;
    }

    int get_ISBN() const {           // Adding const to getter methods indicates that these methods do not modify the state of the object
        return ISBN;
    }

    int get_Year() const {           // Adding const to getter methods indicates that these methods do not modify the state of the object
        return Year_of_Publication;
    }
};

class Library {

    std::vector<Book> books ;            // vectors of book objects

    public:      //make sure to add public, otherwise the methods can't be used !!

        void addBook (Book book);            // make sure to add the return type when declaring methods !
        void display_Books ();
        void searchBook (std::string searchTerm);
};

