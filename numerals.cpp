// File name: numerals.cpp
// Author: George Perez
// Class: CSCI 371 Fall 2018
// Description: This program simulates a Finite state Machine takes in roman numerals
//              1-100 and checks whether or not they belong in the language.

#include <iostream>
#include <string>
using namespace std;

int main()
{
  int states[5][16] =
  {
    {1,  2,   3, -1,  5,  2, 12, 12, 12, 12, 12, -1,  2, -1, -1, -1},
    {4,  11, -1, -1, -1, -1,  4,  4,  4,  4,  4, -1, 13, -1, -1, -1},
    {6,  14, -1, -1, -1, -1,  7,  8, -1, -1,  6, -1, 14, -1, -1, -1},
    {10, -1, -1, -1, -1, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {15, -1, -1, -1, -1, -1,  9, -1, -1, -1, -1, -1, -1, -1, -1, -1}
  };

  while(!cin.eof()) // While still receiving input
  {
    int currentState = 0; // The state that M is currently in
    int letter; // The equivalent position of the characters in the langauge
    int count = 0; // To iterate through the string
    string input; // What the user inputs

    cout << "Enter your roman numeral (e.g.: VII): ";
    getline(cin, input);

    if((input.length() == 0) || (input.length() > 8)) {currentState = -1;}
    // The empty string is not a part of the language (roman numerals had no way of representing 0)
    // If the string is greater than 8 characters, it is not within the range of 1-100 (longest string is LXXXVIII(88))

    while((count != input.length()) && (currentState != -1)) // While not at the end of the string and not in a dead state
    {
      switch(input[count])
      {
        case 'I': letter = 0; break; // If the character in the iterator is I, convert it to a 0
        case 'V': letter = 1; break;
        case 'X': letter = 2; break;
        case 'L': letter = 3; break;
        case 'C': letter = 4; break;
        default: currentState = -1; continue; // If a bad character comes in, start loop over and deny it
        // Note: If a space comes before / in-between / after any input, it is considered rejected
        // because a space is technicially a character
      }

      currentState = states[letter][currentState];
      count++; // Moving through the string
    }

    if(currentState == -1) {cout << "Rejected" << endl;} // If the current state is a -1, it is a dead state
    else                   {cout << "Accepted" << endl;} // Otherwise, it's in an accept state
  }
}
