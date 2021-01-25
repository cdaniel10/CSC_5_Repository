/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 13, 2021, 12:36 PM
 * Purpose:  Sums
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    short int      inp, //Input
            posSum = 0, //Positive Sum
            negSum = 0, //Negative Sum
                 total; //Total Sum
                 
    //Map inputs -> outputs
    cout<<"Input 10 numbers, any order, positive or negative\n";
    cin>>inp;
    (inp>0) ? posSum+=inp : negSum+=inp;
    cin>>inp;
    (inp>0) ? posSum+=inp : negSum+=inp;
    cin>>inp;
    (inp>0) ? posSum+=inp : negSum+=inp;
    cin>>inp;
    (inp>0) ? posSum+=inp : negSum+=inp;
    cin>>inp;
    (inp>0) ? posSum+=inp : negSum+=inp;
    cin>>inp;
    (inp>0) ? posSum+=inp : negSum+=inp;
    cin>>inp;
    (inp>0) ? posSum+=inp : negSum+=inp;
    cin>>inp;
    (inp>0) ? posSum+=inp : negSum+=inp;
    cin>>inp;
    (inp>0) ? posSum+=inp : negSum+=inp;
    cin>>inp;
    (inp>0) ? posSum+=inp : negSum+=inp;
    
    total = posSum + negSum;
    
    //Display the outputs
    cout<<"Negative sum ="<<setw(4)<<negSum<<endl;
    cout<<"Positive sum ="<<setw(4)<<posSum<<endl;
    cout<<"Total sum    ="<<setw(4)<<total;
    
    //Exit stage right or left!
    return 0;
}
