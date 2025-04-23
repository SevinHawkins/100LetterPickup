#include <iostream>
#include <sstream>
#include <algorithm>
#include "Dictionary.h"
#include "LetterPool.h"
#include "GameTimer.h"
#include "LetterAlgo/LAlgo.h"

int main() {
    Dictionary dict("words_alpha.txt");
    auto selectedWords = wordsToFillPool(dict, 100);
    LetterPool letterPool;
    letterPool.generateFromWords(selectedWords);

    std::cout << "Welcome to 100 Letter Pickup!\n";
    std::cout << "You have 4 minutes to use as many letters as possible.\n";
    std::cout << "Available letters: " << letterPool.getAvailLetters() << "\n";
    std::cout << "Type '0' to quit.\n";

    GameTimer timer;
    timer.start();

    std::string input;
    while (true) {
        std::cout << "enter a word:¨: ";
        std::getline(std::cin, input);
        if (input == "0") {
            std::cout << "Game over. You're such a pussy.\n";
            break;
        }
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (dict.isWord(input)) {
            if (letterPool.useLetters(input)) {
                std::cout << "Word accepted: " << input << "\n";
            } else {
                std::cout << "Not enough letters for: " << input << "\n";
            }
        } else {
            std::cout << "Not a valid word: " << input << "\n";
        }
        std::cout << "Available letters: " << letterPool.getAvailLetters() << "\n";
        if (letterPool.isEmpty()) {
            std::cout << "No more letters, you win!\n";
            break;
        }
        if (timer.elapsedSeconds() > 240) {
            std::cout << "Time's up! You lose!\n";
            break;
        }
        std::cout << "Time left: " << 240 - timer.elapsedSeconds() << " seconds\n";
    }
    return 0;
}