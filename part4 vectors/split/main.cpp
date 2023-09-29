#include <iostream>
#include <string>
#include <vector>


// TODO: Implement split function here
// Do not change main function


std::vector<std::string> split(const std::string& input, char separator, bool ignoreEmpty = false)
{
    std::vector<std::string> ignored;
    std::string current;

    for(char c : input){
        if (c == separator){
            if(!ignoreEmpty  || !current.empty()){
                ignored.push_back(current);
            }
            current.clear();
        }else{
            current += c;
        }
        }
    if(!ignoreEmpty || !current.empty()){
        ignored.push_back(current);
    }

    return ignored;
}

int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
