#include "book.hh"

Book::Book(const std::string& author, const std::string& title)
    : author_(author), title_(title), is_borrowed_(false) {
}

void Book::loan(const Date& loan_date) {
    if (!is_borrowed_) {
        is_borrowed_ = true;
        loan_date_ = loan_date;
        return_date_ = loan_date;
        return_date_.advance(28); // Eräpäivä 28 päivää lainauspäivästä eteenpäin
    }
}

bool Book::renew() {
    if (is_borrowed_) {
        Date new_due_date = return_date_;
        new_due_date.advance(28); // Uusi eräpäivä 28 päivää eteenpäin
        return_date_ = new_due_date;
        return true; // Uusiminen onnistui
    }
    return false; // Kirjaa ei voi uusia koska se ei ole lainassa
}

void Book::give_back() {
    is_borrowed_ = false;
    loan_date_ = Date(); // Tyhjä päivä lainauspäiväksi
    return_date_ = Date();  // Tyhjä päivä eräpäiväksi
}


void Book::print() const {
    std::cout << author_ << " : " << title_ << std::endl;
    if (is_borrowed_) {
        std::cout << "- loaned: ";
        loan_date_.print();
        std::cout << "\n- to be returned: ";
        return_date_.print();
    } else {
        std::cout << "- available\n";
    }
}
