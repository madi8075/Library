#ifndef PATRON_H
#define BOOK_H

#include <string>
#include <iostream>
#include <vector>
#include "Book.h"

class Book;

class Patron {

    // Declaring what's in each patron
    private:
        std::string name;
        std::string patronID;
        std::vector<Book*> borrowedBooks;

    public:
        // Patron Constructor
        Patron(std::string name, std::string id);

        // Methods
        void display() const;
        void borrowBook(Book& book);
        void returnBook(Book& book);
        void getPatronID() const;

        // Overload method
        friend std::ostream& operator<<(std::ostream& os, const Patron& patron);
};

#endif //PATRON_H