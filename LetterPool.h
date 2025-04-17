#pragma once
#include <unordered_map>
#include <string>
#include <vector>

class LetterPool {
public:
    // Constructor
    LetterPool();
    void generateFromWords(const std::vector<std::string>& words);
    bool useLetters(const std::string& word);
    std::string getAvailLetters() const;
    bool isEmpty() const;

private:
    std::unordered_map<char, int> letters;
};