// A2_Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #2 : Question 2
// Due Date: 9/7/22


/* PURPOSE:
The purpose of this program is to copy the data stored in the array and store it in a vector, in which we displayed 
what was stored in both the array and vector using a function template. Afterwards, we computed the average of 
the ages we were given and displayed it. 
*/

//_______________________________________________________________________________________________________________
//Below are the libraries used in this program. 

#include <iostream>
#include <string>
#include <vector> 
using namespace std;

//Below are the functions that we used/created to execute this program. 

//a. displayAll to display each arrays "age" and "names."
//Using template to display any type of array.
template <class T1>
void displayAll(T1 x[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}
//c. DisplayAll to display each vector "vage" and "vnames"
//Using template to display any type of vector.
template <class T2>
void DisplayAll(vector<T2> x)
{
    for (unsigned int i = 0; i < x.size(); ++i) //unsigned int is always greater than or equal to 0
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

//d. computeAgeAve to compute and return their age average using a vector. 
float computeAgeAve(vector<int> age)
{
    float total = 0;

    for (unsigned int i = 0; i < age.size(); ++i) 
    {
        total = total + age[i];
    }

    float average = total / age.size();
    return average;
}

//Below is the main function. 

int main()
{
    int age[5] = { 33, 67, 55, 72, 44 };
    string names[3] = { "Trump", "Clinton", "Obama" };

    //call a function template displayAll to display each arrays age and names.
    cout << "Array age: ";
    displayAll(age, 5);
    cout << "Array names: ";
    displayAll(names, 3);

    //b. copy array age into vector vage, and array names into vector vnames
    vector<int> vage;
    for (int i = 0; i < 5; ++i)
    {
        vage.push_back(age[i]);
    }
    vector<string> vnames;
    for (int i = 0; i < 3; ++i)
    {
        vnames.push_back(names[i]);
    }

    cout << endl;

    //Call function template DisplayAll to display each vector 
    cout << "Vector vage: ";
    DisplayAll(vage);
    cout << "Vector vnames: ";
    DisplayAll(vnames);

    cout << endl;

    //Call function computeAgeAve to compute and return their age average. Display the result.
    float average = computeAgeAve(vage);
    cout << "Age Average = " << average << endl; 
     
    
    return 0;
}

//Below is a copy of the output screen. 