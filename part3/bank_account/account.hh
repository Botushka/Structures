#ifndef ACCOUNT_HH
#define ACCOUNT_HH
#include <iostream>
#include <string>
using namespace std;

class Account
{

public:



    // Constructor
    Account(const std::string& owner, bool has_credit = false);

    // More methods
    void set_credit_limit(int limit){
        if(has_credit_){
            credit_limit_ = limit;
        } else{
            cout << "Error: This is not a credit card account." << endl;
        }
    }

    void save_money(int amount){
         balance_ += amount;
    }

    void take_money(int amount) {
        if (balance_ >= amount || (has_credit_ && balance_ + credit_limit_ >= amount)) {
            balance_ -= amount;
            cout << owner_ << " : " << iban_ << " : " << balance_ << " euros" << endl;
        } else {
            cout << "Cannot take money: ";
            if (has_credit_) {
                cout << "credit limit overflow" << endl;
            } else {
                cout << "balance underflow" << endl;
            }
        }
    }

    void transfer_to(Account& other, int amount) {
        if (balance_ >= amount) {
            balance_ -= amount;
            other.save_money(amount);
            cout << amount << " euros taken: new balance of " << iban_ << " is " << balance_ << " euros" << endl;
        } else if (has_credit_ && balance_ + credit_limit_ >= amount) {
            balance_ -= amount;
            other.save_money(amount);
            cout << amount << " euros taken: new balance of " << iban_ << " is " << balance_ << " euros" << endl;
        } else {
            cout << "Cannot take money: ";
            if (has_credit_) {
                cout << "credit limit overflow" << endl;
            } else {
                cout << "balance underflow" << endl;
            }
            cout << "Transfer from " << iban_ << " failed" << endl;
        }
    }


    void print() const {
            cout << owner_ << " : " << iban_ << " : " << balance_ << " euros" << endl;
        }

private:
    // Generates IBAN (based on running_number_ below).
    // Allows no more than 99 accounts.

    void generate_iban();

    // Used for generating IBAN.
    // Static keyword means that the value of running_number_ is the same for
    // all Account objects.
    // In other words, running_number_ is a class-wide attribute, there is
    // no own copies of it for each object of the class.
    static int running_number_;

    // More attributes/methods
       string owner_;
       string iban_;
       bool has_credit_;
       int credit_limit_;
       int balance_;
};


#endif // ACCOUNT_HH
