/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 26, 2021, 11:59 PM
 * Purpose: Present Value
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Function Prototypes
float psntVal(float, float, int);  //Calculates Present Value

//Execution Begins Here
int main(int argc, char** argv){
    
    //Declare Variables
    float fv, yrs, pv;
    int iRate;
    
    //Initialize Variables
    cout<<"This is a Present Value Computation\n";
    cout<<"Input the Future Value in Dollars\n";
    cin>>fv;  //Future Value in USD
    cout<<"Input the Number of Years\n";
    cin>>yrs;  //Number of Years
    cout<<"Input the Interest Rate %/yr\n";
    cin>>iRate; //Interest Rate
    
    //Map Inputs -> Outputs
    pv = psntVal(fv, yrs, iRate);  //Present Value
    
    //Output Data
    cout<<"The Present Value = $"<<setprecision(2)<<fixed<<pv;
    
    //Exit
    return 0;
}

float psntVal(float fv, float yrs, int iRate){
    return (fv/(pow(1+(iRate/100.),yrs)))+.005;
}