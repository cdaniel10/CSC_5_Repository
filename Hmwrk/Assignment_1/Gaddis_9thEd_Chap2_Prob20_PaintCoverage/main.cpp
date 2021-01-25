/* 
 * File:   main.cpp
 * Author: Christian Daniel
 *
 * Created on January 10, 2021, 11:59 PM
 * Purpose: How Much Paint is Needed
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
    unsigned short height, // Height of Fence
                   length, // Length of Fence
                   pntCov, // Paint Coverage Per Gallon
                  srfArea, // Surface Area to paint in Ft^2
                  numGlns; // Number of Gallons of Paint
    
    //Initialize Variables
    height=6;   //Height in Feet
    length=100; //Length in Feet
    pntCov=340; //Paint Coverage Per Gallon in Squared Feet
    
    //Map Inputs to Outputs -> Process
    srfArea=2*2*height*length;//Paint Twice Front and Back of the Fence
    numGlns=srfArea/pntCov+1;
    
    //Display Inputs/Outputs
    cout<<numGlns<<" gallons of paint are required to paint a ";
    cout<<height<<"ft x "<<length<<"ft fence front and back, twice!";
    
    //Exit the Program - Cleanup
    return 0;
}