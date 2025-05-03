#include "file_reader.h"
#include <fstream>
#include <iostream>

std::vector<std::string> readFile(const std::string& path) {
    std::vector<std::string> lines;
    std::ifstream file(path);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << path << "\n";
        return lines;
    }

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}
