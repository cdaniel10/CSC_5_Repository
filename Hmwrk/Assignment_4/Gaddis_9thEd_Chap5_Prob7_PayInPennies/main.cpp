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
    unsigned days, dSalary=1, total=0, dollars, pennies;

    //Input
    do{
        cin>>days;    //Days worked
    }while(days<=0);  //Must Be More Than 0
    
    //Salary
    for(unsigned short i=1; i<=days; i++){
        total+=dSalary;
         dSalary*=2;    //Salary Doubles Daily
    }
    dollars = total/100;
    pennies = total%100;
    
    //Display the outputs
    cout<<"Pay = $"<<dollars<<".";
    if (pennies<10)cout<<'0';
    cout<<pennies;
    
    //Exit stage right or left!
    return 0;
}