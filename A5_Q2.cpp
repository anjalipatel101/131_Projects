// A5_Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
///// Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #5 : Question 2
// Due Date: 9/28/22

// PURPOSE:
// Use STACKPAC.h to determine whether a given phrase is a palindrome or not.
//______________________________________________________________________________________________________________
//Below are the libraries used in this program. 

#include <iostream>
#include <string>
#include "STACKPAC.h"

using namespace std;

//Main function below.
int main()
{
    //Declaration/creation of the stacks needed for this program. 
    Stack<char, 80> bottomTop;
    Stack<char, 80> topBottom;
    Stack<char, 80> Temp; //used to switch between the two stacks above
    int numPhrases;
    int phraseCounter = 1;   //need the counter to count the number of phrases that the user would like to try
    char c;

    //clearing stacks
    bottomTop.clearStack();
    topBottom.clearStack();
    Temp.clearStack();

    //getting the user input about the number of phrases they would like to try
    cout << "How many phrases would you like to try? ";
    cin >> numPhrases;
    cin.ignore(); //flushing new line character

    //checking to see if all phrases are palindromes until number of phrases is reached
    //then it will exit the while loop

    while (phraseCounter <= numPhrases)
    {
        cout << "Enter a phrase: ";
        while (cin.get(c), c != '\n')
        {
            if (isalpha(c))
            {
                bottomTop.pushStack(c);
                Temp.pushStack(c);
            }
        }
        // pop Temp in topBottom stack
        while (!Temp.emptyStack())
        {
            char x = Temp.popStack();
            topBottom.pushStack(x);
        }

        //use topBottom and bottomTop stacks to check for palindrome
        bool isPal = true;
        while (!bottomTop.emptyStack() && isPal)//bottomTop and topBottom are same size, choose one
        {
            char x = topBottom.popStack(); //pop a char from topBottom stack
            char y = bottomTop.popStack(); //pop a char from bottomTop
            //convert both letters in x and y to lowercase
            x = tolower(x); y = tolower(y);
            //compare letters in x and y, if not the same the phrase is not
            //a plindrome
            if (x != y)
                isPal = false;
        }
        if (isPal == true)
            cout << "\tThis phrase is a palindrome" << endl;
        else
            cout << "\tThis phrase is not a palindrome" << endl;

        phraseCounter++; //incrementing once executed to go again until number of phrases is reached
    }

    return 0;
}