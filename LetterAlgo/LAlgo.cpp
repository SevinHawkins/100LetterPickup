#include "LAlgo.h"
#include <algorithm>
#include <random>

std::vector<std::string> wordsToFillPool(Dictionary& dict, int maxLetters) {
    std::vector<std::string> words = dict.getWords();
    std::vector<std::string> selectedWords;
    std::string letterBlob;

    std::mt19937 rng((std::random_device())());
    std::shuffle(words.begin(), words.end(), rng);

    for (const auto& word : words) {
        if (word.length() > 6 || word.length() < 3) {
            continue; // Skip words that are too long or too short
        }
        if (letterBlob.size() + word.length() <= maxLetters) {
            letterBlob += word;
            selectedWords.push_back(word);
        } else {
            break; // Stop if adding the word exceeds maxLetters
        }
    }
    return selectedWords;
}