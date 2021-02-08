/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on February 7th, 2021, 7:30 PM
 * Purpose:  Lottery Binary Search
 */
#include <iostream>
#include <string>
using namespace std;

//function prototypes
void stringSort(string [], int);
bool binarySearchString(const string [], string, int);

int main()
{
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                                "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                                "Taylor, Terri", "Johnson, Jill",
                                "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                                "James, Jean", "Weaver, Jim", "Pore, Bob",
                                "Rutherford, Greg", "Javens, Renee",
                                "Harrison, Rose", "Setzer, Cathy",
                                "Pike, Gordon", "Holland, Beth" };

    //call sorting function on array names
    stringSort(names, NUM_NAMES);

    //declare variable to store user input
    //prompt user to enter it then read from keyboard
    string searchName;
    cout << "Enter the name to search:\n";
    //get the input name using getline function
    //which reads the string until Enter is pressed
    // by user
    getline(cin, searchName);

    //call function to binary search input name
    //and display message according to function output
    if(binarySearchString(names, searchName, NUM_NAMES))
        cout << searchName << " was found in list!\n";
    else
        cout << searchName << " was not found!\n";

    return 0;
}

void sortNames(string names[], int NUM_NAMES){
    //will sort in ASCENDING order

    //declare variables to start from beginning of array
    //and to store the temporary min name and index
    int startScan, minIndex;
    string minName;

    for(int i = 0; i < NUM_NAMES-1; i++){
        low = names[i];
        lowIndx = i;
        for(int j = i+1; j < NUM_NAMES; j++){
            if(names[j] < low){
                low = names[j];
                lowIndx = j;
            }
        }
        names[lowIndx] = names[i];
        names[i] = low;
    }
}

bool binarySearchString(string names[], string nm2Fnd, int NUM_NAMES){
    //perform binary search
    //declare variables to hold starting and final positions
    //of subsearch, and boolean to know if the name has
    //been found
    int first = 0, //initialize first index to first element
        last = arraySize-1, //initialize last index to last element
        middle;

    //continue loop until first and last indexes have not overlapped
    while(first <= last){
        //get middle element
        middle = (first + last) / 2;
        //check if middle element is equal to our value
        if(names[middle] == searchName){
            return true;
        }
        //if middle element is greater than our value
        //update search space to first half of array
        else if(names[middle] > searchName){
            last = middle - 1;
        }
        //if middle element is less than our value
        //update search space to second half of array
        else if(names[middle] < searchName){
            first = middle + 1;
        }
    }
    //if loop has finished and the number has not
    //been found, return false
    return false;
}

    
