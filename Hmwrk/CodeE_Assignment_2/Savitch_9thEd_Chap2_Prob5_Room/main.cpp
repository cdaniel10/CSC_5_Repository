/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 13, 2021, 12:36 PM
 * Purpose:  Maximum Capacity
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    unsigned short maxCap, //Maximum Capacity
                   numPpl; //Number of People in Room
    
    //Map inputs -> outputs
    cout<<"Input the maximum room capacity and the number of people\n";
    cin>>maxCap>>numPpl;
    
    (numPpl<=maxCap) ? cout<<"Meeting can be held.\nIncrease number of people by "<<maxCap-numPpl<<" will be allowed without violation." :
                       cout<<"Meeting cannot be held.\nReduce number of people by "<<numPpl-maxCap<<" to avoid fire violation.";

    //Exit stage right or left!
    return 0;
}