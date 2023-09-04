// A2_Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #2 : Question 1
// Due Date: 9/7/22


/* PURPOSE:
The purpose of this program is to copy the data stored in the file.txt into a 3D array called students. With information about 
whether the person is an undergrad or grad, what campus they're from, and their gender, we were able to display the data from the file 
and output it according to that information.
*/

//_______________________________________________________________________________________________________________

// Below are the sets of libraries that we use to execute the code. 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Below are our created functions which we called in the program (see below).

//a. Copy data from the file into array
void copyData(string fname, int x[2][4][2]) //have to input the numbers i believe to match his conditions for array
{
    //open the file 
    fstream f;
    f.open(fname, ios::in);
    //copy data from file into array
    for (int r = 0; r < 2; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            for (int sl = 0; sl < 2; ++sl)
            {
                f >> x[r][c][sl];
            }
        }
    }
    f.close(); //close the file 
}

//b. Display the total number of students. 
//display total number of students no matter grad or under grad, campus, or gender
int findTotalStud(int x[2][4][2])
{
    int total = 0;
    for (int type = 0; type < 2; ++type)
    {
        for (int campus = 0; campus < 4; ++campus)
        {
            for (int gender = 0; gender < 2; ++gender)
            {
                total += x[type][campus][gender];
            }
        }
    }
    return total;
}

//c. Display the total number of female students. 
int findFemales(int x[2][4][2])
{
    int total = 0;
    for (int type = 0; type < 2; ++type)
    {
        for (int campus = 0; campus < 4; ++campus)
        {
            int gender = 0;
            {
                total += x[type][campus][gender];
            }
        }
    }
    return total;
}

//d. Display the total number of graduate students.
int findGrads(int x[2][4][2])
{
    int total = 0;
    int type = 1; //in rows (grad = 1)
    {
        for (int campus = 0; campus < 4; ++campus)
        {
            for (int gender = 0; gender < 2; ++gender)
            {
                total += x[type][campus][gender];
            }
        }
    }
    return total;
}

//e. Display the number of under-graduate students in the Orange campus.
int findunderGradOrange(int x[2][4][2])
{
    int total = 0;
    int type = 0; //in rows undergrad = 0
    {
        int campus = 1; //in columns orange campus = 1
        {
            for (int gender = 0; gender < 2; ++gender)
            {
                total += x[type][campus][gender];
            }
        }
    }
    return total;
}

//Below is our main function. 

int main()
{
    //Below are the calling statments to produce the outputs for the calculated arrays. 
    int stud[2][4][2]; //3d array 2 row, 4 col, 2 slices
    copyData("file.txt", stud);
    int totalStud = findTotalStud(stud);
    int totalFemales = findFemales(stud);
    int totalGrad = findGrads(stud);
    int underGradOrange = findunderGradOrange(stud);

    //Below are the statements to display the totals found above 
    cout << "Total Number of Students: " << totalStud << endl;
    cout << "Total Number of Female Students: " << totalFemales << endl;
    cout << "Total Number of Graduate Students: " << totalGrad << endl;
    cout << "Total Number of Under-Graduate Students in the Orange Campus: " << underGradOrange << endl;

    return 0;
}

//Below is a copy of the output screen.