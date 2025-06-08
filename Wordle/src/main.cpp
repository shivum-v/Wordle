#include <iostream>
#include <vector>
#include <string>
#include "wordle.h"
using namespace std;

void gameHandler(Wordle& w, int turn) {
    string guess;
    while (turn < 6) {
        cout << "Guess: ";
        cin >> guess;

        if (w.findGuess(guess)) {
            bool win = w.checkGuess(guess);
            if (win) {
                cout << "You win!" << endl;
                return;
            } else {
                ++turn;
            }
        } else {
            cout << "Invalid Guess" << endl;
            continue;
        }
    }

    cout << "Out of guesses!" << endl;
    cout << "Word: " << w.getGuess() << endl;
    return;
}

int main() {
    string command;
    cout << "Select an action: Play / Quit: ";
    while (cin >> command) {
        if (command == "Quit") {
            break;
        } else if (command == "Play") {
            Wordle w;
            gameHandler(w, 1);
            cout << "Select an action: Play / Quit: ";
            continue;
        } else {
            cout << "Invalid command" << endl;
            cout << "Select an action: Play / Quit: ";
            continue;
        }
    }
}