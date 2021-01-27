/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 26, 2021, 11:59 PM
 * Purpose:  Factorial
 */

//System Libraries
#include <iostream>
using namespace std;

//Function Prototypes
int fctrl(int);  //Function to Calculate Factorial

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n;

    //Process/Map inputs to outputs
    cout<<"This program calculates the factorial using a function prototype found in the template for this problem.\n";
    cout<<"Input the number for the function.\n";
    cin>>n;
    
    //Output data
    cout<<n<<"! = "<<fctrl(n);
    
    //Exit stage right!
    return 0;
}

int fctrl(int n){
    if(n > 1) return n*fctrl(n - 1);
    else return 1;
}