/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 12, 2021, 12:36 PM
 * Purpose:  Paycheck
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

    unsigned short payRt,  //Pay Rate
                   hrsWrk;  //Hours Worked
    float         grosPay;  //Gross Pay
    
    cout<<"This program calculates the gross paycheck.\n";
    cout<<"Input the pay rate in $'s/hr and the number of hours.\n";
    cin>>payRt>>hrsWrk;
    
    grosPay = (hrsWrk >= 40) ? payRt*(hrsWrk*2-40) : payRt*hrsWrk; //Pay rate for hours worked above 40 is doubled
        
    cout<<"Paycheck = $"<<setw(7)<<setprecision(2)<<fixed<<grosPay;
    
    return 0;
}