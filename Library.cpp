#include "Library.h"
#include <iostream>
#include <fstream>

// Add new book to the library
void Library::addBook(const Book& book) {
    books.push_back(book);
}

// Add new patron to the library
void Library::addPatron(const Patron& patron) {
    patrons.push_back(patron);
}

// Display all books in the library using overload
void Library::displayAllBooks() const {
    for (const auto& book : books) {
        std::cout << book << "test\n";
    }
}

// Display all patrons in the library
void Library::displayAllPatrons() const {
    for (const auto& patron : patrons) {
        std::cout << patron << "\n";
    }
}

// Find a book by ISBN, loop through each book and search
Book* Library::findBookByISBN(const std::string& isbn) {
    for (auto& book : books) {
        if (book.getISBN() == isbn) {
            return &book;
        }
    }
    return nullptr;
}

// Find a patron by ID, search for matching id
Patron* Library::findPatronByID(const std::string& id) {
    for (auto& patron : patrons) {
        if (patron.getPatronID() == id) {
            return &patron;
        }
    }
    return nullptr;
}

// Borrow a book for a patron
void Library::borrowBook(const std::string& patronID, const std::string& isbn) {
    Patron* patron = findPatronByID(patronID);
    Book* book = findBookByISBN(isbn);
    if (patron && book && book->getAvailability()) {
        patron->borrowBook(*book);
    } else {
        std::cout << "Cannot borrow book.\n";
    }
}

// Return a book from a patron
void Library::returnBook(const std::string& patronID, const std::string& isbn) {
    Patron* patron = findPatronByID(patronID);
    Book* book = findBookByISBN(isbn);

    if (patron && book && !book->getAvailability()) {
        patron->returnBook(*book);
    }
    else {
        std::cout << "Cannot return book.\n";
    }
}

// Save library data to a file
void Library::saveLibraryToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    // check if file is correct and print information
    if (outFile.is_open()) {
        outFile << "Library Books:\n";

        for (const auto& book : books) {
            outFile << book << "\n";
        }

        outFile << "Library Patrons:\n";
        for (const auto& patron : patrons) {
            outFile << patron << "\n";
        }

        outFile.close();
        std::cout << "Library data saved to " << filename << "\n";
    }

    else {
        std::cout << "Error: Could not open file for saving.\n";
    }
}
