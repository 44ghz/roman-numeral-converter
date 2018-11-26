# roman-numeral-converter
This program utilizes a finite state machine to parse a string of Roman numerals 1-100. It was an assignment from my Theoretical Foundations course in Fall 2018.

/// Purpose ///

This program is meant to simulate a finite state machine and determines whether or not the string input belongs in the language of Roman numerals. Once the user inputs a string, they are simply told whether the string is in the language (Accepted), or if it's not (Rejected).

/// How to use ///

Simply run the program and input the desired numeral when prompted. After the string is entered, it will be tested and will return either Accepted (if the string is a roman numeral 1-100), or Rejected (if it's not). 

/// How it works ///

The program works by taking the string the user provides and compares it to a finite state table. While parsing the string, it will continue to move through the table until it has reached either an accept state or a dead state. When the string has been fully parsed, the program outputs the result of the state table.
