#ifndef BOOK_H // prevent multiple initialization
#define BOOK_H

#include <string>
#include <iostream>

class Book {

    private:
        std::string title;
        std::string author;
        std::string ISBN;
        bool isAvailable;

    public:
        // Constructor
        Book(std::string title, std::string author, std::string ISBN);

        //Display method
        void display() const;

        // Methods to borrow or return a book
        void borrowBook();
        void returnBook();

        // Methods for printing out various book info
        bool getAvailability() const;
        std::string getISBN() const;

        // Overload method for << operator to print
        friend std::ostream& operator<<(std::ostream& os, const Book& book);

};

#endif // BOOK_H