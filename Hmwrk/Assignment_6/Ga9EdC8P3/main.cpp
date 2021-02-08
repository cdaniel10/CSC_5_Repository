/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on February 7th, 2021, 7:30 PM
 * Purpose:  Lottery Binary Search
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
bool binSrch(int [],int,int);
void markSrt(int [],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    const int SIZE=10;  //Number of Lottery Tickets
    int ticket[SIZE]={13579, 26791, 26792, 33445, 55555,  //Ticket 5-Digit Number 
                      62483, 77777, 79422, 85647, 93121};
    int winNum;        //5-Digit Number To Find
    markSrt(ticket,SIZE);  //Sort Numbers
    
    //Initialize Variables
    cout<<"Enter the winning number:\n";
    cin>>winNum;  //Winning Number
    
    //Map Inputs to Outputs -> Process
    if(binSrch(ticket,SIZE,winNum)){
        //Display Inputs/Outputs
        cout<<"Congratulations you have won!";
    }else{
        cout<<"No winning numbers.";
    }

    //Exit the Program - Cleanup
    return 0;
}

bool binSrch(int a[],int n,int val){
    //Initialize the Range to search
    int low=0,high=n-1, midPnt;
    //Loop until found
    do{
        midPnt=(high+low)/2;
        if(a[midPnt]==val){
            return true;  //If Found
        }else if(a[midPnt]>val){
            high=midPnt-1;
        }else{
            low=midPnt+1;
        }
    }while(low<=high);
        
    return false;  //If Not Found
}

void markSrt(int a[],int n){
    for(int i=0;i<n-1;i++){      //Loop for each position in List
        for(int j=i+1;j<n;j++){  //Loop to swap with first in List
            if(a[i]>a[j]){       //Put the smallest at top of List
                a[i]=a[i]^a[j];  //In place Swap
                a[j]=a[i]^a[j];  //In place Swap
                a[i]=a[i]^a[j];  //In place Swap
            }
        }
    }
}