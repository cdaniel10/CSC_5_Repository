/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 12, 2021, 12:36 PM
 * Purpose:  Trigonometry
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    
    //Declare Variables
    float num;
    
    //Map inputs -> outputs
    cout<<"Calculate trig functions\n";
    cout<<"Input the angle in degrees.\n";
    cin>>num;
    
    //Display the outputs
    cout<<setprecision(0)<<fixed<<"sin("<<num<<") = "<<setprecision(4)<<fixed<<sin(num*M_PI/180)<<endl;
    cout<<setprecision(0)<<fixed<<"cos("<<num<<") = "<<setprecision(4)<<fixed<<cos(num*M_PI/180)<<endl;
    cout<<setprecision(0)<<fixed<<"tan("<<num<<") = "<<setprecision(4)<<fixed<<tan(num*M_PI/180);
    
    //Exit stage right or left!
    return 0;
}