#include <iostream>
#include "file_reader.h"
#include "analyzer.h"

int main() {
  
    std::string filePath;
    char repeat = 'y';  // Variable to control the loop

    while (repeat == 'y' || repeat == 'Y') {
        std::cout << "Enter the path of the text file to analyze: ";
        std::getline(std::cin, filePath);

        std::vector<std::string> lines = readFile(filePath);

        if (lines.empty()) {
            std::cout << "File is empty or couldn't be read.\n";
        } else {
            analyzeText(lines);
        }

        std::cout << "Do you want to analyze another file? (y/n): ";
        std::cin >> repeat;
        std::cin.ignore();  // To ignore the newline character left by std::cin
    }

    std::cout << "Exiting File Analyzer. Goodbye!\n";
    return 0;
}
