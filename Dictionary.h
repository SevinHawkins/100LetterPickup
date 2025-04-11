#pragma once
#include <unordered_set>
#include <vector>
#include <string>

class Dictionary {
public:
    Dictionary(const std::string& filepath);
    bool isWord(const std::string& word) const;
    std::vector<std::string> getWords() const;

private:
    std::unordered_set<std::string> words;
};