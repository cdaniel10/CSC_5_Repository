/* 
 * File:   main.cpp
 * Author: Christian Daniel
 *
 * Created on January 10, 2021, 11:59 PM
 * Purpose: Annual Pay
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
    float payAmnt, //Pay Amount in USD
           payPrd, //Pay Period = Every 2 weeks
          anualPy; //Annual Pay in USD
    
    //Initialize Variables
    payAmnt=2200;
    payPrd=26;
            
    //Map Inputs to Outputs -> Process
    anualPy=payAmnt*payPrd; //$2200 for 26 Pay Periods
            
    //Display Inputs/Outputs
    cout<<"Annual Pay: $"<<anualPy<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}