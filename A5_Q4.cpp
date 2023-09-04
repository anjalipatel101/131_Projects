// A5_Q4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #5 : Question 4
// Due Date: 9/28/22
/* PURPOSE:
Writing a recursive function to return the nth Fibonacci number.
*/
//_______________________________________________________________________________________________________________
//Below are the libraries used in this program. 

#include <iostream>
using namespace std; 

//Function to calculate the numbers in the fibonacci series. 

int fib (int n) 
{
    if (n < 2) {
        return n;
    }
    else {
        return (fib(n - 1) + fib(n - 2));
    }
}

//Below is the main function which outputs the value from the fibonacci series 
//which is determined from the nth term put in by the user. 

int main()
{
    int num;
    
    cout << "Enter a number: ";
    cin >> num;

//Outputs the specific number from the nth term that the user inputed. Subtracts 1 because indexes start at 0;
//thus, to get the value from the series the 10th value is stored at the 9th index. (For all values)

    cout << "Fibonacci Number: " << fib(num - 1) << endl;
    return 0;
}