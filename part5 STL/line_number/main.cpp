#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputFileName, outputFileName;

    // Kysy input- ja output-tiedostonimet käyttäjältä
    std::cout << "Input file: ";
    std::cin >> inputFileName;
    std::cout << "Output file: ";
    std::cin >> outputFileName;

    // Avataan input-tiedosto
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Error! The file " << inputFileName << " cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }

    // Avataan output-tiedosto
    std::ofstream outputFile(outputFileName);

    std::string line;
    int lineNumber = 1;

    // Luetaan input-tiedosto rivi kerrallaan ja kirjoitetaan se output-tiedostoon
    while (std::getline(inputFile, line)) {
        outputFile << lineNumber << " " << line << std::endl;
        lineNumber++;
    }

    // Suljetaan tiedostot
    inputFile.close();
    outputFile.close();


    return 0;
}

