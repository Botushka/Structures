#include <iostream>
#include <string>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif

bool is_palindrome_recursive(const std::string& s, int start, int end) {
    // Base case: If the start and end indices meet or cross, it's a palindrome
    if (start >= end) {
        return true;
    }

    // Check if the characters at the start and end positions are the same
    if (s[start] != s[end]) {
        return false;
    }

    // Recursively check the remaining substring (excluding the start and end characters)
    return is_palindrome_recursive(s, start + 1, end - 1);
}

bool palindrome_recursive(std::string s)
{
  RECURSIVE_FUNC
  // Do not remove RECURSIVE_FUNC declaration, it's necessary for automatic testing to work
  // ------------
   return is_palindrome_recursive(s, 0, s.length() - 1);

  // Add your implementation here
}

// Do not modify rest of the code, or the automated testing won't work.
#ifndef UNIT_TESTING
int main()
{
    std::cout << "Enter a word: ";
    std::string word;
    std::cin >> word;

    if(palindrome_recursive(word)){
        std::cout << word << " is a palindrome" << std::endl;
    } else {
        std::cout << word << " is not a palindrome" << std::endl;
    }
}
#endif
