#include "analyzer.h"
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

void analyzeText(const std::vector<std::string>& lines) {
    int lineCount = lines.size();
    int wordCount = 0;
    int charCount = 0;
    int charNoSpace = 0;
    std::string longestWord;
    std::unordered_map<std::string, int> wordFreq;

    for (const auto& line : lines) {
        charCount += line.length();
        for (char c : line) {
            if (c != ' ') charNoSpace++;
        }

        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            wordCount++;
            wordFreq[word]++;
            if (word.length() > longestWord.length()) {
                longestWord = word;
            }
        }
    }

    // Sort words by frequency
    std::vector<std::pair<std::string, int>> sortedWords(wordFreq.begin(), wordFreq.end());
    std::sort(sortedWords.begin(), sortedWords.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Word Cloud Output
    std::cout << "\n🌈 Word Cloud:\n";
    for (const auto& pair : sortedWords) {
        std::cout << pair.first << ": " << std::string(pair.second, '*') << " (" << pair.second << " times)\n";
    }

    // Basic Statistics
    std::cout << "\n📄 File Analysis Result:\n";
    std::cout << "-------------------------\n";
    std::cout << "🧾 Lines: " << lineCount << "\n";
    std::cout << "📏 Words: " << wordCount << "\n";
    std::cout << "🔡 Characters (with spaces): " << charCount << "\n";
    std::cout << "🔡 Characters (no spaces): " << charNoSpace << "\n";
    std::cout << "🚀 Longest word: " << longestWord << "\n";
}
