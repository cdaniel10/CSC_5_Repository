/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 12, 2021, 12:36 PM
 * Purpose:  Insurance
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {
    
    //Declare Variables
    int     repCost, //Replacement Cost in USD
             minIns; //Minimum Insurance recommended in USD
    float   prctIns; //Percent cost that should be Insured

    //Initialize or input i.e. set variable values
    prctIns = 0.8;
    
    //Map inputs -> outputs
    cout<<"Insurance Calculator\n";
    cout<<"How much is your house worth?\n";
    cin>>repCost;

    //Display the outputs
    cout<<"You need $"<<repCost*prctIns<<" of insurance.";
    
    //Exit stage right or left!
    return 0;
}