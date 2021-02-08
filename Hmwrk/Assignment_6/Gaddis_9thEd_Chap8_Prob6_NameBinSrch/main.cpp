/* 
 * File: main.cpp
 * Author: Christian Daniel
 * Created on: February 7th, 11:00PM
 * Purpose:  Name Binary Searh
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
bool binSrch(string [],int,string);
void sortNames(string[],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const int NUM_NAMES=20;
	string names[NUM_NAMES]={"Collins, Bill", "Smith, Bart", "Allen, Jim",
							 "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
							 "Taylor, Terri", "Johnson, Jill",
							 "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
							 "James, Jean", "Weaver, Jim", "Pore, Bob",
							 "Rutherford, Greg", "Javens, Renee",
							 "Harrison, Rose", "Setzer, Cathy",
							 "Pike, Gordon", "Holland, Beth" };
	string nm2Fnd, temp;
	
    //Initialize Variables
    bool found;
    cout<<"Enter a name to search for:\n";
    getline(cin,nm2Fnd);
    
    //Process or map Inputs to Outputs
    sortNames(names,NUM_NAMES);
    found=binSrch(names,NUM_NAMES,nm2Fnd);
    
    //Display Outputs
    if (found)cout<<"The name was found";
    else cout<<"The name was not found";
    
    //Exit stage right!
    return 0;
}

bool binSrch(string a[],int n,string val){
    //Initialize the Range to search
    int low=0,high=n-1;
    int midPnt;
    
    //Loop until found
    do{
        midPnt=(high+low)/2;
        if(a[midPnt]==val){
            return true;
        }else if(a[midPnt]>val){
            high=midPnt-1;
        }else{
            low=midPnt+1;
        }
    }while(low<=high);
    return false;
}

void sortNames(string names[], int NUM_NAMES){
    string temp;
    int tIndx;
    //Alphabeticl Order
    for(int i=0;i<NUM_NAMES-1;i++){
        temp=names[i];
        tIndx=i;
        for(int j=i+1;j<NUM_NAMES;j++){
            if(names[j]<temp){
                temp=names[j];  //Store Lowest ASCII Value In temp
                tIndx=j;  //Store Index
            }
        }//Swap To Front
        names[tIndx]=names[i];
        names[i]=temp;
    }
}