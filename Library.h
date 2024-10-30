#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include "Book.h"
#include "Patron.h"
#include <vector>

class Library {
    // Declaring what's in each library
    private:
        std::vector<Book> books;
        std::vector<Patron> patrons;

    public:
        // Methods to add new book or patron
        void addBook(const Book& book);
        void addPatron(const Patron& patron);
        
        // display info about either book or patron
        void displayAllBooks() const;
        void displayAllPatrons() const;

        // Look up either book or patron
        Book* findBooksByISBN(const std::string& isbn);
        Patron* findPatronByID(const std::string& id);

        // Methods for changing available status
        void borrowBook(const std::string& patronID, const std::string& isbn);
        void returnBook(const std::string& patronID, const std::string& isbn);
        
        // Save Library info to a file
        void saveLibraryToFile(const std::string& filename) const;

};

#endif