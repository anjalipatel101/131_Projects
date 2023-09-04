// A6_Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #6 : Question 1
// Due Date: 10/12/22

/* PURPOSE:
The purpose of this program is to write a program to find and display the value of f(15), 
and determine its run-time.
*/

//_______________________________________________________________________________________________________________
//Below are the libraries used in this program. 

#include <iostream>
#include <ctime>
using namespace std;

long f(int n)
{
    if (n == 1) {
        return 2;
    } 
    else {
        return 2 * f(n - 1);
    }
}

//Below is the main function
int main()
{
    int start, end;
    //save time before calling function
    start = clock();
   
    //call the function
    cout << f(15) << endl;

    //save time after executing function
    end = clock();

    //display the run-time  
    
    cout << "Run-time = " << (end - start)/1000  << endl;

    system("pause");
    return 0;
    

}
