#ifndef HANGMAN_FUNCTIONS_H
#define HANGMAN_FUNCTIONS_H

#include "functions.h"

using namespace std;
int intro();
int startGame();
void printUserString(string yes);
bool checkEnteredLetter(string &likey, string &bam, char boom, int &lGuess);
bool checkIfGuessed(string Guessed, string actual);
bool choice(int word, int let);
#endif //HANGMAN_FUNCTIONS_H
