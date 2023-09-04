// A6B_Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.

//// Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #6B : Question 1
// Due Date: 10/12/22

/* PURPOSE:
Write a program to evaluate the following postfix expression that is given. See below for details: 
Expression:  tom jerry + mickey 23 * - $ 
*/
//__________________________________________________________________________________________________

//Below are the libararies used for this program
#include <iostream>
#include "STACKPAC.h"
#include <string>
using namespace std;

//Below is the main function. 
int main()
{
  //  tom jerry + mickey 23 * - $
   // creation/initialization of variables, stack, and clearing of stack p
    int varA = 2, varB = 3, x, varC = 4, value, c, y, r;

    Stack<int, 10> p;
    p.clearStack();
    string id;

    cout << "Enter a postfix expression: ";
    cin >> id;
    cout << endl;
     
    while (cin >> id, id != "$")
    {
        //checks whether the input is a number: if it is, then it converts it to it's # value

        if (isdigit(id[0]))
        {
            value = stoi(id);
            p.pushStack(value);
        }
        if (id == "varA")
            p.pushStack(varA);
        else if (id == "varB")
            p.pushStack(varB);
        else if (id == "varC")
            p.pushStack(varC);

        else if (id == "+")
        {
            x = p.popStack();
            c = p.popStack();
            y = p.popStack();
            r = y + x;
            p.pushStack(r);
        }
        else if (id=="*")
        {
            x = p.popStack();
            c = p.popStack();
            y = p.popStack();
            r = y * x;
            p.pushStack(r);
        }
        else if (id == "-")
        {
            x = p.popStack();
            c = p.popStack();
            y = p.popStack();
            r = y * x;
            p.pushStack(r);
        }
    }

    //pop the stack to see the result
    cout << "Enter the value of tom: " ;
    cin >> varA;
    cout << endl;


    cout << "Enter the value of jerry: " ;
    cin >> varB;
    cout << endl;

    cout << "Enter the value of mickey: ";
    cin >> varC;
    cout << endl;

    cout << "Value of the expression is :"  << p.popStack() << endl;

    system("pause");
    return 0;
}











