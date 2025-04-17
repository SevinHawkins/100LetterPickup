#include "LetterPool.h"
#include <cctype>

// Constructor
LetterPool::LetterPool() {}

void LetterPool::generateFromWords(const std::vector<std::string>& words) {
    letters.clear();
    for (const auto& word : words) {
        for (char c : word) {
            if (std::isalpha(c)) {
                letters[std::tolower(c)]++;
            }
        }
    }
}

bool LetterPool::useLetters(const std::string& word) {
    std::unordered_map<char, int> temp = letters;
    for (char c : word) {
        if (std::isalpha(c)) {
            c = std::tolower(c);
            if (temp[c] > 0) {
                temp[c]--;
            } else {
                return false; // Not enough letters
            }
        }
    }
    letters = temp; // Update the pool
    return true; // Successfully used letters
}

std::string LetterPool::getAvailLetters() const {
    std::string result;
    for (const auto& [c, count] : letters) {
        result.append(count, c);
    }
    return result;
}

bool LetterPool::isEmpty() const {
    for (const auto& [c, count] : letters) {
        if (count > 0) {
            return false;
        }
    }
    return true;
}