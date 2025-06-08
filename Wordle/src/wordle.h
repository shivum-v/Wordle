#ifndef Wordle_H
#define Wordle_H
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <random>
#include <sstream>
#include "words.h"

class Wordle {
        std::vector<std::string> wordbank;
        std::string guess;
        std::unordered_map<char, int> frequency;

    public:
        Wordle();
        ~Wordle() = default;
        bool findGuess(std::string&);
        bool checkGuess(std::string&);
        std::string getGuess() const;
};

#endif