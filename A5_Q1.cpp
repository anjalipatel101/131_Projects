// A5_Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #5 : Question 1
// Due Date: 9/28/22


/* PURPOSE:
The purpose of this program is to convert an integer number at base 10 (decimal) to base 2, 8, or 16. It'll then
output the integer after converting to base 2, 8, or 16. The program will ask if you'd like to continue to convert
numbers at base 10 to a new base.
*/

//_______________________________________________________________________________________________________________

//Below are the libraries used in this program.  
#include <iostream>
#include <string>
#include "STACKPAC.h"

using namespace std;

//Below is our main function where we convert from base 10 to base 2,8, or 16
int main()
{
    //initializing variables
    int n;
    int newBase;
    int remainder;
    Stack<int, 20> sBase;

    //clearing stack
    sBase.clearStack();

    //getting user input
    cout << "Enter a number at base 10: ";
    cin >> n;
    cout << "Enter a new base (2, 8, 16): ";
    cin >> newBase;

    //bad input check
    while (newBase != 2 && newBase != 8 && newBase != 16)
    {
        cout << "Please answer with intgers 2, 8, or 16." << endl;
        cin >> newBase;
    }

    //beginning of displaying answer
    cout << "\t" << n << " base 10 is ";

    //pushing answer into stack
    while (n != 0)   // as long as n is not zero, find remainder = n % 2 and push remainder in stack
    {
        remainder = n % newBase;
        sBase.pushStack(remainder);
        n = n / newBase;
    }
    //displaying answer through stack
    while (!sBase.emptyStack())
    {
        if (newBase == 16) //considering base 16, alphabet for hexadecimal
        {
            int x = sBase.popStack();
            if (x <= 9) // x = 0,1,...,9
                cout << x;
            else //x = 10,11,...,15, making cases for 10-15 to print letters
            {
                switch (x)
                {
                case 10:
                    cout << 'A';
                    break;
                case 11:
                    cout << 'B';
                    break;
                case 12:
                    cout << 'C';
                    break;
                case 13:
                    cout << 'D';
                    break;
                case 14:
                    cout << 'E';
                    break;
                case 15:
                    cout << 'F';
                    break;
                }
            }
        }
        else
        {
            int x = sBase.popStack(); //displaying for bases 2 & 8
            cout << x;
        }
    }
    cout << " base " << newBase << endl;

    //user input to continue the program
    cout << "CONTINUE(y/n)? ";
    string choice; //answer, conditional, yes, no
    bool run = true;
    cin.ignore(); //ignoring new line character from cin, flush newline character
    while (run)
    {
        getline(cin, choice); //get user input to answer continue question
        if (choice != "y" && choice != "n") //must answer in "y" or "n" format
        {
            cout << "Please answer with either \'y\' or \'n\'." << endl;
            run = true; //get user input until recieved a "y" or "n"
        }
        else if (choice == "y") //running program again for numbers chosen
        {
            cout << "Enter a number at base 10: ";
            cin >> n;
            cout << "Enter a new base (2, 8, 16): ";
            cin >> newBase;

            while (newBase != 2 && newBase != 8 && newBase != 16) //bad input check
            {
                cout << "Please answer with intgers 2, 8, or 16." << endl;
                cin >> newBase;
            }

            cout << "\t" << n << " base 10 is ";

            while (n != 0)   // as long as n is not zero, find remainder = n % 2 and push remainder in stack
            {
                remainder = n % newBase;
                sBase.pushStack(remainder);
                n = n / newBase;
            }

            while (!sBase.emptyStack())
            {
                if (newBase == 16)
                {
                    int x = sBase.popStack();
                    if (x <= 9)  //x = 0,1,...,9
                        cout << x;
                    else   //x = 10,11,...,15
                    {
                        switch (x)
                        {
                        case 10:
                            cout << 'A';
                            break;
                        case 11:
                            cout << 'B';
                            break;
                        case 12:
                            cout << 'C';
                            break;
                        case 13:
                            cout << 'D';
                            break;
                        case 14:
                            cout << 'E';
                            break;
                        case 15:
                            cout << 'F';
                            break;
                        }
                    }
                }
                else
                {
                    int x = sBase.popStack();
                    cout << x;
                }
            }
            cout << " at base " << newBase << endl;

            cout << "CONTINUE(y/n)? "; //asking user if they would like to continue program again
            cin.ignore(); //flushing new line character from cin
            run = true; //get user input again
        }
        else if (choice == "n")
        {
            run = false; //stops while loop and no longer asks for user input
        }
    }

    system("pause");
    return 0;
}

//Below is a copy of the output screen