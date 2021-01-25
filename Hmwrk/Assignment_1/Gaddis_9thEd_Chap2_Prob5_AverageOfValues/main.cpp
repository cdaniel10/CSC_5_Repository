/* 
 * File:   main.cpp
 * Author: Christian Daniel
 *
 * Created on January 10, 2021, 11:59 PM
 * Purpose: Average of Values
 */

// System Libraries
#include <iostream>  //I/O Library
using namespace std;

//Users Libraries
//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays
//Function Prototypes
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float a, b, c, d, e, sum, avg;
    
    //Initialize Variables
    a=28;
    b=32;
    c=37;
    d=24;
    e=33;
    
    //Map Inputs to Outputs -> Process
    sum=a+b+c+d+e; //Sum of variables a,b,c,d,e
    avg=sum/5;     //Average of Variables^
    
    //Display Inputs/Outputs
    cout<<"Average: "<<avg<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}