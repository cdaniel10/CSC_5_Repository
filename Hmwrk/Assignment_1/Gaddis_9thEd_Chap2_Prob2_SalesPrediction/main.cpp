/* 
 * File:   main.cpp
 * Author: Christian Daniel
 *
 * Created on January 10, 2021, 11:59 PM
 * Purpose: Sales Prediction
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
    float prtGen, //Percent generated from total sales
         totlSls, //Total Sales in USD
          mnyGen; //Money Generated from Total Sales in USD
    
    //Initialize Variables
    prtGen=.58;
    totlSls=8.6e6;
    
    //Map Inputs to Outputs -> Process
    mnyGen=prtGen*totlSls; //Percent Generated * Total Sales
    
    //Display Inputs/Outputs
    cout<<"The East Coast division will generate $"<<int(mnyGen)<<", if sales reach $"<<int(totlSls)<<"."<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}