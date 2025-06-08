#include "wordle.h"
using namespace std;

Wordle::Wordle() {
    // Populate wordbank
    istringstream iss{words};
    string w;
    while (iss >> w) { wordbank.push_back(w); }

    random_device rd;
    uniform_int_distribution<int> dist(0, wordbank.size() - 1);
    guess = wordbank[dist(rd)];

    for (auto c : guess) frequency[c]++;
}

bool Wordle::findGuess(string& g) {
    if (g.size() != 5) { return false; }

    // Capitalize guess
    for (int i = 0; i < g.size(); ++i) {
        if ('a' <= g[i] && g[i] <= 'z') {
            g[i] -= 32;
        } else if ('A' <= g[i] && g[i] <= 'Z') {
            continue;
        } else {
            return false;
        }
    }

    // Perform Binary Search
    int left = 0;
    int right = wordbank.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        string mid = wordbank[middle];

        if (g == mid) {
            return true;
        } else if (g < mid) {
            right = middle - 1;
        } else if (mid < g) {
            left = middle + 1;
        }
    }

    return false;
}

bool Wordle::checkGuess(string& g) {
    string result = "-----";
    unordered_map<char, int> freq = frequency;

    // Checking Green
    for (int i = 0; i < g.size(); ++i) {
        if (g[i] == guess[i]) {
            result[i] = 'G';
            freq[g[i]]--;
        }
    }

    // Checking Yellow
    for (int i = 0; i < g.size(); ++i) {
        if (result[i] == 'G') continue;

        if (freq[g[i]] > 0) {
            result[i] = 'Y';
            freq[g[i]]--;
        } 
    }

    if (result == "GGGGG") {
        return true;
    } else {
        cout << "Result: " << result << endl;
        return false;
    }
}

string Wordle::getGuess() const { return guess; }
