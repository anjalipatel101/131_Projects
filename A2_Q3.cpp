// A2_Q3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #2 : Question 3
// Due Date: 9/7/22


/* PURPOSE:
The purpose of this program is to read a sentence and display the frequency of each of the letters included in the given phrase. We need to 
iterate through the list of letters in the alphabet with a while loop for the array to display the frequency. 
*/
//_______________________________________________________________________________________________________________

//Below are the libraries that we used to execute this program. 
#include <iostream>out
#include <string>
#include <iomanip>
using namespace std; 

//Below is the main function

int main() {
    // Initializing the variables. 
    char str[] = "life is about making impact, not making income";
    int i = 0;
    int alphabet[26] = { 0 };
    int j;

    //This while loop determines the frequency of the characters/letters that are in the string. 

    while (str[i] != '\0') { //goes until the end of the string of characters
        if (str[i] >= 'a' && str[i] <= 'z') {
            j = str[i] - 'a'; //getting numerical value of each letter
            ++alphabet[j]; //alphabet stores the frequency of the letters 
        }
        ++i;
    }

    // Below is the code to display the output of the program above. 
    cout  << setw(15) << "Letters"  <<  setw(20) << "Frequencies " <<  endl;
    cout << "     -------------------------------" << endl;
  

    //Below is the the code to display the frequency of each letter in the table. 
    for (i = 0; i < 21; i++) //"u" (21) is the last letter in the alphabet in that sentence
        if (alphabet[i] > 0) { //displays only letters that appear in the sentence because they are 1 or more
            cout << setw(12) << char(i + 'a') << setw(15) << alphabet[i] << endl; //displays in alphabetical order
        }
        
    return 0;
};

//Below is a copy of the output screen. 