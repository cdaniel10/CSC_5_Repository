/* 
 * File:   main.cpp
 * Author: Christian Daniel
 *
 * Created on January 12, 2021, 11:59 PM
 * Purpose: Budget Percentage
 */

// System Libraries
#include <iostream> //I/O Library
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {
      
    //Declare Variables
    float milBdgt, fedBdgt, mlPrcnt;
    
    //Initialize Variables
    milBdgt = 7.0e11f; //Military Budget = 700 Billion
    fedBdgt = 4.1e12f; //Federal Budget  = 4.1 Trillion
        
    //Map Inputs to Outputs -> Process
    mlPrcnt = (milBdgt/fedBdgt)*100; //Military Budget Percent, of Federal Budget
            
    //Display Inputs/Outputs
    cout<<"The Military Budget is "<<setprecision(4)<<mlPrcnt<<"% of the Federal Budget."<<endl;
            
    //Exit the Program - Cleanup
    return 0;
}