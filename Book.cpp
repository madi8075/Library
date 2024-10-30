#include "Book.h"
#include <iostream>

// Constructor
Book::Book(std::string t, std::string a, std::string isbn)
    : title(t), author(a), ISBN(isbn), isAvailable(true) {}

void Book::display() const{
    std::cout   << "Title: " << title << "\n"
                << "Author: " << author << "\n"
                << "ISBN: " << ISBN << "\n"
                << "Available: " << (isAvailable ? "Yes" : "No") << std::endl;
}

void Book::borrowBook() {
    if(isAvailable) {
        isAvailable = false;
    }
    else {
        std:: cout << "Book is already borrowed.\n";
    }
}

void Book::returnBook() {
    if(!isAvailable) {
        isAvailable = true;
    }
    else {
        std::cout << "Book already returned.\n";
    }
}

bool Book::getAvailability() const {
    return isAvailable;
}

std::string Book::getISBN() const {
    return ISBN;
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os  << "Title: " << book.title << "\n"
        << "Author: " << book.author << "\n"
        << "ISBN: " << book.ISBN << "\n"
        << "Available: " << (book.isAvailable ? "Yes" : "No") << std::endl;
    return os;
}