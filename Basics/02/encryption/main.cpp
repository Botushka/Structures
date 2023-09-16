#include <iostream>
#include <string>
#include <cctype>

using namespace std;


bool validKey(const  string& key){
    if (key.length() != 26){
        cout << "Error! The encryption key must contain 26 characters." << endl;
        return false;
    }

    for(char i = 'a'; i <= 'z'; i++){
        if(key.find(i) == string::npos){
            cout << "Error! The encryption key must contain all alphabets a-z." << endl;
            return false;
        }
    }

    for (size_t i = 0; i < key.length(); i++) {
          if (!islower(key[i])) {
              cout << "Error! The encryption key must contain only lower case characters." << endl;
              return false;
          }
      }

    return true;
}

bool validText(const string& text){
    for (size_t i = 0; i < text.length(); i++) {
          if (!islower(text[i])) {
              cout << "Error! The text to be encrypted must contain only lower case characters." << endl;
              return false;
          }
      }

    return true;
}

  string encryptText(const string& text, const string& key) {
    string encryptedText = text;

    for (size_t i = 0; i < text.length(); i++) {
        if (islower(text[i])) {
            encryptedText[i] = key[text[i] - 'a'];
        }
    }

    return encryptedText;
}

int main()
{
    string  encText;
    string  encKey;
    cout << "Enter the encryption key: ";
    cin >> encKey;

    if(!validKey(encKey)){
        return 1;
    }

    cout << "Enter the text to be encrypted: ";
    cin >> encText;

    if(!validText(encText)){
        return 1;
    }

    string encryption = encryptText(encText, encKey);
    cout << "Encrypted text: " << encryption << endl;

    return 0;
}
