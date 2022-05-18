#include <iostream>
#include <string>
#include "functions.h"
#include <cstdlib>

using namespace std;

int intro()
{
    bool introVar = true;

    char userChoiceOne;

    while(introVar)                                                     //while variable intro var is true
    {
        cout<< "Would you like to play the game?"<<endl;
        cout<<"a = Yes"<<endl<<"b =  No"<<endl;                         //print out the menu

        cin>>userChoiceOne;

        if((userChoiceOne!='a') && (userChoiceOne!='b'))                //if user choices are not a or b
        {
            cout << "Wrong choice try again" << endl;                   //then say its a wrong choice and ask them again
        }
        else
        {
            if(userChoiceOne == 'a')                                    //if it is 'a' then start the game
            {
                introVar = false;
                startGame();
            } else                                                      //if its not a then its b and quit the game
            {
                return 0;
            }
        }
    }
}

int startGame()
{
    string array[21] = {"kiwi","canoe","doberman", "frame", "frugal", "orange", "frigate",
                                   "beauceron", "postal","basket","cabinet","birch","machine","mississippian",
                                   "destroyer","mutt","fruit","behemoth","valerian","joseph","brotherhood"};



    int v1 = rand()%array->size();
    int size_of_RanString;

    cout << array[v1];
    string gameString = array[v1];
    size_of_RanString = gameString.length();



    string user_String(size_of_RanString, '_');                         //creates a string of _ that are user guesses
    string user_Guesses="";

    int word_Tries = 3;
    int letter_Tries = 5;
    bool gameOver = false;
    char letter_Guess;
    string word_Guess;

    while (!gameOver)
    {
        bool Guess = false;
        bool rightGuess;
        cout<<"Here's the word you are guessing: ";
        printUserString(user_String);
        while(!Guess)
        {
            if ((!choice(word_Tries,letter_Tries)) && (letter_Tries > 0)) {
                cout << "Now, guess a letter that could be a part of this word: ";
                cin >> letter_Guess;
                if ((letter_Guess <= 'z') && (letter_Guess >= 'A')) {
                    if ((letter_Guess > 'Z') && letter_Guess < 'a') {
                        cout << "Thats not a letter try again" << endl;
                    } else {
                        Guess = true;
                    }
                } else {
                    cout << "Thats not a letter try again" << endl;
                }
            }//end if choice
            else {
                cout << "Enter Word choice: ";
                cin >> word_Guess;
                if (word_Guess != gameString) {
                    word_Tries--;
                } else {
                    cout << "You won!!" << endl;
                    cout << "The word was : " << gameString << endl;
                    return 0;
                }
            }

            rightGuess = checkEnteredLetter(gameString, user_String, letter_Guess, letter_Tries);

            if (!rightGuess) {
                user_Guesses.push_back(letter_Guess);
            }

            cout << "Here are the letters you've guessed: ";
            cout << user_Guesses << endl;

            if (checkIfGuessed(user_String, gameString)) {
                cout << "You won!!" << endl;
                cout << "The word was : " << gameString << endl;
                return 0;
            }

            if (word_Tries < 1) {
                cout << "Game over!" << endl;
                cout << "The word was: " << gameString << endl;
                return 0;
            }
        }
    }

}

void printUserString(string yes)
{
    if(yes.length()>0)
    {
        for (int i = 0; i <= yes.length() - 1; i++)
        {
            cout << yes[i] << " ";
        }
    }
    cout << endl;
}

bool checkEnteredLetter(string &likey, string &bam, char boom, int &lGuess)
{
    int weGottem = 0;
    for(int i=0; i<likey.length();i++)
    {
        if(likey[i]==boom)
        {
            bam[i]=boom;
            weGottem++;
        }
    }

    lGuess--;

    if(weGottem == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool checkIfGuessed(string Guessed, string actual)
{
    if(Guessed == actual)
    {
        cout<<"You guessed the word!"<<endl;
        return true;
    }
    return false;
}

bool choice(int word, int let)
{
    char dec;
    bool menu=true;

    if(let<=0)
    {
        return true;
    }

    cout<<"Would you like to guess a word or a letter?(W/L)"<<endl;
    while (menu)
    {
        cin >> dec;
        switch (dec)
        {
            case 'W':
            case 'w':
                return true;
            case 'L':
            case 'l':
                return false;
            default:
                cout<<"Sorry wrong choice"<<endl;
                break;
        }
    }
}