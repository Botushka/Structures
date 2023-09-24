#ifndef BOOK_HH
#define BOOK_HH

#include <iostream>
#include <string>
#include "date.hh"

class Book {
public:
    // Constructor
    Book(const std::string& author, const std::string& title);

    // Loan the book
    void loan(const Date& loan_date);

    // Renew the book
    bool renew();

    // Give the book back
    void give_back();

    // Print book information
    void print() const;

private:
    std::string author_;
    std::string title_;
    bool is_borrowed_;
    Date loan_date_;
    Date return_date_;
};


#endif // BOOK_HH

