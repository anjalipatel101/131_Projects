// A1Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.\

// Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #1 : Question 2 
// Due Date: 8/31/22


/* PURPOSE: 
* The purpose of this program is to use template functions to display and sort an array. Using these templates, we're
* able to use one function to pass through different variable types which reflect the data stored in the array and sort it
(using the predefined function from the <algorithim> library). 
*/

//_______________________________________________________________________________________________________________

// Below are the libraries we used to execute this program. 

#include <iostream>
#include <string>
#include <algorithm> //used for sorting array
using namespace std;

// Below are the template classes that help us pass different data types into our functions. See below for the display and sort functions. 
template <class T1>
void displayArray(T1 x[], int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        cout << x[i] << '\t';
    }
    cout << endl;
}

template <class T2>
void sortArray(T2 x[], int n) //using <algorithm> library to for sortArray
{
    sort(x, x + n);
}

//Below is the main function. 

int main() {
    //initializing arrays
    int a[6] = { 44,55,22,88,33,11 };
    string  months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec" };
    char vowels[5] = { 'E','U','A','I','O' };

    //Displaying original array and sorting array a
    cout << "Original array a: ";
    displayArray(a, 6);
    sortArray(a, 6);

    //Displaying sorted array a
    cout << "Sorted array a:   ";
    displayArray(a, 6);

    cout << endl;

    //Displaying original array and sorting array months
    cout << "Original array months: ";
    displayArray(months, 12);
    sortArray(months, 12);

    //Displaying sorted array months
    cout << "Sorted array months:   ";
    displayArray(months, 12);

    cout << endl; 

    //Displaying original array and sorting array vowels
    cout << "Original array vowels:   ";
    displayArray(vowels, 5);
    sortArray(vowels, 5);

    //Displaying sorted array vowels
    cout << "Sorted array vowels:     ";
    displayArray(vowels, 5);

    cout << endl;
      

    return 0;
}

//copy of the output screen