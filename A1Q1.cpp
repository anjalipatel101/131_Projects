// A1Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #1 : Question 1
// Due Date: 8/31/22


/* PURPOSE:
The purpose of this program is to copy the data stored in the data.txt file into an array struct called presidents. From there,
we were able to display the data from the file in a table using <iomainp>  members so it refelcted our desired output. 
*/

//_______________________________________________________________________________________________________________

// Below are the libraries we used to execute this program. 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Below are the declarations and functions that we used to create the array we wanted to store values into, 
// and how we copied the data into the array as well as displayed the data accordingly. 

//declaring a array of structures (records of ---> president's name, years served, and wives)
struct president
{
    string    presName;
    string    yearsServed;
    string    wifeName;

};
president presidents[6]; //6 locations/indexes for 6 presidents in the file

//copying data to an array
void copyData(string fname, president x[], int n) { //function with arguments string, array, and integer
    //opening of the file
    fstream  f;
    f.open(fname, ios::in);
    //copy data from file into array
    for (int i = 0; i < n; ++i) 
    {
        f >> x[i].presName >> x[i].yearsServed >> x[i].wifeName; //initializes location of presName, yearsServed, and wifeName
    }
    f.close(); //close the file outside of for loop
}

//displaying data from array
void displayAll(president x[], int n) 
{   //formatting output so that the name, years served, and wife's name line up
    cout << left << setw(16) << "NAME" << setw(16) << "YEARS SERVED " << right << setw(8) << "WIFE'S NAME" << endl;
 
    for (int i = 0; i < n; ++i) 
    {
        //By using setfill() we're able to replace any spaces in the table with '.' . 
        cout << setfill('.');         
        cout << left << setw(16) << x[i].presName << setw(16) << x[i].yearsServed << right << setw(11) << x[i].wifeName << endl;
    }
    cout << endl;
}

//Below is the main function: We are calling the statements to copy data and display data. 
int main() {

    copyData("data.txt", presidents, 6);
    displayAll(presidents, 6);
    return 0;

}

//copy of the output screen

