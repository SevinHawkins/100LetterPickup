#include "Dictionary.h"
#include <fstream>
#include <algorithm>

Dictionary::Dictionary(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open())  {
        throw std::runtime_error("Could not open file: " + filepath);
    }
    std::string word;
    while(file >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.insert(word);
    }
}

bool Dictionary::isWord(const std::string& word) const {
    return words.find(word) != words.end();
}

std::vector<std::string> Dictionary::getWords() const {
    return std::vector<std::string>(words.begin(), words.end());
}

