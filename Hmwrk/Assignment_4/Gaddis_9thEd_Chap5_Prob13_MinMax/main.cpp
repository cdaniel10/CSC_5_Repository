/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 22, 2021, 12:36 PM
 * Purpose:  Min-Max
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    short int inp, max, min;

    //Initialize Variables
    cin>>inp;

    max=inp;
    min=inp;
    
    //Map inputs -> outputs
    while (true){
        //Input
        cin>>inp;
        
        //Exit Loop
        if (inp==-99) break;
        
        //Max and Min
        (inp>max)?max=inp:0;  //Find New Max
        (inp<min)?min=inp:0;  //Find New Min
    }
    cout<<"Smallest number in the series is "<<min<<endl;
    cout<<"Largest  number in the series is "<<max;

    //Exit stage right or left!
    return 0;
}