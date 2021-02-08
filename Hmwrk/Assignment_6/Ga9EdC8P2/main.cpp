/* 
 * File:   
 * Author: Christian Daniel
 * Created on: February 6th, 11:00PM
 * Purpose:  Lottery Linear Search
 */
 
//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
bool linSrch(int [],int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    const int SIZE=10;  //Number of Lottery Tickets
    int ticket[SIZE]={13579, 26791, 26792, 33445, 55555,  //Ticket 5-Digit Number 
                      62483, 77777, 79422, 85647, 93121};
    int winNum;        //5-Digit Number to find
    
    //Initialize Variables
    cout<<"Enter the winning number:\n";
    cin>>winNum;  //Winning Number
    
    //Map Inputs to Outputs -> Process
    if(linSrch(ticket,SIZE,winNum)){
        //Display Inputs/Outputs
        cout<<"Congratulations you have won!";
    }else{
        cout<<"No winning numbers.";
    }
    
    //Exit the Program - Cleanup
    return 0;
}

bool linSrch(int ticket[],int SIZE,int winNum){
    for(int i=0;i<SIZE;i++){
        if(ticket[i]==winNum){
            return true;  //If Found
        }
    }
    return false;  //If Not Found
}