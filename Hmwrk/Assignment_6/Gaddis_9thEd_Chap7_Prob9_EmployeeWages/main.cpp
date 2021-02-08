/* 
 * File: main.cpp 
 * Author: Christian Daniel
 * Created on: February 6th, 2021, 10:00PM
 * Purpose:  Employee Wages
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const int SZE=7;
    int empId[SZE]={5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489},  //Employee ID's
        hours[SZE];  //Hours Worked
    float payRate[SZE],  //Pay Rate
          wages[SZE];  //Wage
    
    //Initialize Variables
    for(int i=0; i<SZE; i++){
        cout<<"Enter employee "<<empId[i]<<"'s pay rate:\n";
        cin>>payRate[i];
        cout<<"Enter employee "<<empId[i]<<"'s hours work:\n";
        cin>>hours[i];
    }
    
    //Process or map Inputs to Outputs
    for(int i=0; i<SZE; i++){
        wages[i]=payRate[i]*hours[i];  //Calculate Wage
    }
    
    //Display Outputs
    for(int i=0; i<SZE; i++){
        cout<<"Employee "<<empId[i]<<"'s gross pay $"<<setprecision(2)<<fixed<<wages[i]<<endl;
    }
    
    //Exit stage right!
    return 0;
}