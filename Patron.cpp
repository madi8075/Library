#include "Book.h"
#include "Patron.h"
#include <iostream>
#include <algorithm> // For searching

// Constructor
Patron::Patron(std::string n, std::string id)
    : name(n), patronID(id) {}

// Display patron info
void Patron::display() const {
    std::cout   << "Patron Name: " << name << "\n"
                << "Patron ID: " << patronID << "\n"
                << "Borrowed Books: " << borrowedBooks.size() << std::endl;
    for(const auto& book : borrowedBooks) {
        std::cout << "- " << *book << "\n"; // Dereference each book pointer to display its info
     }
}

void Patron::borrowBook(Book& book) {
    if(book.getAvailability()) {
        borrowedBooks.push_back(&book); // adds book to patron's list of borrowed books
        book.borrowBook(); // mark that book has been borrowed
    }
}

void Patron::returnBook(Book& book) {
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), &book);

    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it); // Remove from patron's returned books and mark available
        book.returnBook();
    }
    else {
        std::cout << "Patron is not borrowing this book.\n";
    }
}

// Get PatronID
std::string Patron::getPatronID() const {
    return patronID;
}

// Overload << for output
std::ostream& operator<<(std::ostream& os, const Patron& patron) {
    os  << "Patron Name: " << patron.name << "\n"
        << "Patron ID: " << patron.patronID << "\n"
        << "Borrowed Books: " << patron.borrowedBooks.size() << std::endl;

    // for loop to list each book by dereferencing pointer
    for (const auto& book : patron.borrowedBooks) {
        os << "- " << *book << "\n"; 
    }
    return os;
}   