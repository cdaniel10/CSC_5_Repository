/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 12, 2021, 12:36 PM
 * Purpose:  Temp
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float c, //Centigrade
          f; //Fahrenheit
    
    //Map inputs -> outputs
    cout<<"Temperature Converter\n";
    cout<<"Input Degrees Fahrenheit\n";
    cin>>f;
    c=5.0/9.0*(f-32); //Convert Fahrenheit to Centigrade
    
    //Display the outputs
    cout<<setprecision(1)<<fixed<<f<<" Degrees Fahrenheit = "<<c<<" Degrees Centigrade";

    //Exit stage right or left!
    return 0;
}