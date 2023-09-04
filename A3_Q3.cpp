// A3_Q3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name: Anjali Patel & Connie Zhu
// Course: Data Structures (CPSC 131), Section 05, Fall 2022
// Assignment: Programming Assignment #3 : Question 3
// Due Date: 9/13/22


/* PURPOSE:
The purpose of this program is to determine if the two strings that the user inputs are anagrams of each other. Taking into 
account that they have the same letters and same length, below is the program to reflect the result. 
*/

//_______________________________________________________________________________________________________________
//Below are the libraries used in this program. 

#include <iostream>
#include <string>

using namespace std;



//try it with cstring library
//checks if the two different strings are anagram (if they have the same length and amount of letters)
bool isAnagram(string st1, string st2) //is this suppose to be an array because it's not working and it's being dumb
{
    //convert strings to lowercase so it won't be case sensitive
    for (int i = 0; i < st1.length(); i++)
    {
        st1[i] = tolower(st1[i]);
    }

    for (int i = 0; i < st2.length(); i++)
    {
        st2[i] = tolower(st2[i]);
    }

   

    //creating count arrays and initializing variables to compare string letters, ignoring spaces in the strings
    int count1[26] = { 0 }; //counting how many in each index for the alphabet
    int count2[26] = { 0 };
    int ascii; //ascii value
    int i = 0; //incrementing integer

    //using while loop to iterate through string 1, using only lowercase values for ascii
    while (st1[i] != '\0') //while it's not at the end of the string
    {
        ascii = st1[i] - 97; //taking "i" index and subtracting the letter value in ascii from lowest ascii (lowercase a) to get index for that letter in count
        count1[ascii] += 1; //adding to that letter in the index
        i++;
    }
    i = 0; //set i to 0 again for count2
    while (st2[i] != '\0')
    {
        ascii = st2[i] - 97;
        count2[ascii] += 1;
        i++;
    }

    //comparing both counts to see if they have the same letters
    for (i = 0; i < 26; ++i)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //Getting user input to see if words are anagram.
    cout << "Enter a string: ";

    string str1;
    getline(cin, str1); //can include delimiter, using default delimiter

    cout << "Enter another string: ";

    string str2;
    getline(cin, str2);

    //check if strings are anagarm then displaying if they are or not
    if (isAnagram(str1, str2))
    {
        cout << "\t\"" << str1 << "\" and \"" << str2 << "\" are anagram" << endl;
    }
    else
    {
        cout << "\t\"" << str1 << "\" and \"" << str2 << "\" are not anagram" << endl;
    }

    //option to continue
    cout << "CONTINUE(y/n)? ";
    string choice; //answer, conditional, yes, no
    bool run = true;
    while (run) {           //while running . . .
        getline(cin, choice); //get user input to answer continue question
        if (choice != "y" && choice != "n") //must answer in "y" or "n" format
        {
            cout << "Please answer with either \'y\' or \'n\'." << endl;
            run = true; //get user input until recieved a "y" or "n"
        }
        else if (choice == "y") //run anagarm check again if "y"
        {
            cout << "Enter a string: ";
            getline(cin, str1);
            cout << "Enter another string: ";
            getline(cin, str2);
            if (isAnagram(str1, str2))
            {
                cout << "\t\"" << str1 << "\" and \"" << str2 << "\" are anagram" << endl;
            }
            else
            {
                cout << "\t\"" << str1 << "\" and \"" << str2 << "\" are not anagram" << endl;
            }

            cout << "CONTINUE(y/n)? ";
            run = true; //get user input again
        }
        else if (choice == "n")
        {
            run = false; //stops while loop and no longer asks for user input
        }
    }

    system("pause"); //briefly stops the program until it recieves a 'y' or 'n' to either continue or terminate the 
                     // as it's waiting for the code to finish, and deallocates resources, waiting for the user to respond

    return 0;

}

// Below is the output in the console. 