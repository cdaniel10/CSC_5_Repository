/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 12, 2021, 12:36 PM
 * Purpose:  Average of 5 Test Scores
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    float inp, // 5 Test Scores
          avg; // Average
    
    //Initialize or input i.e. set variable values
    cout<<"Input 5 numbers to average."<<endl;
    cin>>inp;     // Input 5 Scores
    avg=inp;
    cin>>inp;
    avg+=inp;
    cin>>inp;
    avg+=inp;
    cin>>inp;
    avg+=inp;
    cin>>inp;
    avg+=inp;
    
    //Map inputs -> outputs
    avg=avg/5; // Average of Scores
    
    //Display the outputs
    cout<<"The average = "<<setprecision(1)<<fixed<<avg;

    //Exit stage right or left!
    return 0;
}