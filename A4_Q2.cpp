// A4_Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #4 : Question 2
// Due Date: 9/21/22


/* PURPOSE:
The purpose of this program is to read one name at a time from a file and display the name
followed by the reverse of the same name using the template stack class.
*/

//_______________________________________________________________________________________________________________

//Below are the libraries used in this program.  
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Below is our stack template
//stack class
template <class T, int n>
class Stack
{
private:
    T Element[n];
    int counter;
public:
    void  clearStack()
    {
        counter = 0;
    }
    bool  emptyStack()
    {
        if (counter == 0)
            return true;
        else
            return false;
    }
    bool   fullStack()
    {
        if (counter == n)
            return true;
        else
            return false;
    }
    void   pushStack(T x)
    {
        Element[counter] = x;
        counter++;
    }
    T  popStack()
    {
        counter--;
        return  Element[counter];
    }
};

//Below is our main function 
/*we initialize our variables and stack, open the file to read from the names, put it into the stack, display the names,
reverse the names, and display the reversed names*/
int main() {
    //initializing variables
    string name;
    string c;
    //initializing fstream to read file
    fstream f;
    //initializing stack to recieve the names
    Stack<char, 100> charsN;

    //clearing stack 
    charsN.clearStack();

    f.open("file.txt", ios::in);
    //reading data from file row by row and pushing the name into the stack charsN of chars
    while (f >> name) {
        cout << setfill('.');
        for (int i = 0; i < name.length(); ++i)
        {
            charsN.pushStack(name[i]); //pushing the name into the stack charsN
        }
        string reversed;
        while (!charsN.emptyStack())
        {
            reversed += charsN.popStack(); //popStack to reverse and turn back into a string to right justify
        }
        cout << left << setw(20) << name << right << setw(15) << reversed << endl; //display
    }
    f.close();

    return 0;
}

//Below is a copy of the output screen