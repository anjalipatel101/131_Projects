// A3_Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// // Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #3 : Question 2
// Due Date: 9/13/22


/* PURPOSE:
The purpose of this program is to read a university name, print the first letter of each of the words within the name,
and determine if "of" is anywhere within  the name of the school, and remove it so it's not taking into account by the 
program as the following: University of California Irvine --->  UCI  not UCOI
*/

//_______________________________________________________________________________________________________________
//Below are the libraries used in this program. 
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Below are the functions that were created to call within the main. 
//This removeOf function's purpose is to remove the "of" within the school name so that when we 
//print hte first letter of each word, that it's not include, rather it's removed. 

string removeOf(string Uname)
{
    int n = Uname.find("of");
    if (n != -1)
    {
        Uname.erase(n, 3);
    }

    return Uname;
}


// This function changes every character in the inputed name to be uppercase for the purpose of finding the initials
// and reporting them as uppercase. 

void initials(string uName)
{
    uName[0] = toupper(uName[0]);
    cout << uName[0];

    //printing initial of every word after spaces
    for (int i = 0; i < uName.length(); ++i)
    {
        if (uName[i] == ' ')
        {
            cout << (char)toupper(uName[i + 1]);
        }
    }

    cout << endl;
}

//Below is the main function. In this are of the code, we ask hte user for input, and call the functions that 
// we defined above. From there we printed the values per the instructions. 
int main() {
    cout << "Enter a university name: ";
    string universityName;
    getline(cin, universityName);

    cout << universityName << " or ";
    universityName = removeOf(universityName);
    initials(universityName);

    cout << "\t" << "CONTINUE(y/n)? ";
    string choice; //answer, conditional, yes, no
    bool run = true;
    while (run) { //while running . . .
        getline(cin, choice); //get user input to answer continue question
        if (choice != "y" && choice != "n") //must answer in "y" or "n" format
        {
            cout << "Please answer with either 'y' or 'n'." << endl;
            run = true; //get user input until recieved a "y" or "n"
        }
        else if (choice == "y") //run anagram check again if "y"
        {
            cout << "\t\t" << "Enter a university name: ";
            getline(cin, universityName);
            cout << universityName << " or ";
            universityName = removeOf(universityName);
            initials(universityName);

            cout << "\t" << "CONTINUE(y/n)? ";
            run = true; //get user input again
        }
        else if (choice == "n")
        {
            run = false; //stops while loop and no longer asks for user input
        }
    }

    system("pause"); //briefly stops the program until it recieves a 'y' or 'n' to either continue or terminated the program

    return 0;

}

//Below is the program output in the console. 



