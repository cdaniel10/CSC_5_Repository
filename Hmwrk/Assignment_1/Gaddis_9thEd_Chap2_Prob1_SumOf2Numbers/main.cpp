/* 
 * File:   main.cpp
 * Author: Christian Daniel
 *
 * Created on January 10, 2021, 11:59 PM
 * Purpose: Sum of Two Numbers
 */

// System Libraries
#include <iostream>  //I/O Library
using namespace std;

//Users Libraries
//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays
//Function Prototypes
//Execution Begins Here
int main(int argc, char** argv)
{
    //Initialize the Random Number Seed
    
    //Declare Variables
    unsigned short a, b, total;
    
    //Initialize Variables
    a=50;
    b=100;
    
    //Map Inputs to Outputs -> Process
    total=a+b;  // Sum of a and b
            
    //Display Inputs/Outputs
    cout<<"The sum of "<<a<<" and "<<b<<" is "<<total<<"."<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}