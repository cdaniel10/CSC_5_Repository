/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 22, 2021, 12:36 PM
 * Purpose:  Pay in Pennies
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    unsigned short days;
    float dSalary=0.01f, total=0.00f;

    //Input
    do{
        cin>>days;    //Days worked
    }while(days<=0);  //Must Be More Than 0
    
    //Salary
    for(unsigned short i=1; i<=days; i++){
        total+=dSalary;
         dSalary*=2;    //Salary Doubles Daily
    }
            
    //Display the outputs
    cout<<"Pay = $"<<total;
    
    //Exit stage right or left!
    return 0;
}