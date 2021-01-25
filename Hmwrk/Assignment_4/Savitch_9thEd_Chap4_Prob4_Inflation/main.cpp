/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 22, 2021, 12:36 PM
 * Purpose:  Inflation
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    float crntP, oldP, infRate;
    char choice;

    //Map inputs -> outputs
    do{
        //Input
        cout<<"Enter current price:\n";
        cin>>crntP;  //Current Price
        cout<<"Enter year-ago price:\n";
        cin>>oldP;   //Last Years Price
        
        //Inflation Rate as Percent
        infRate = ((crntP-oldP)/oldP)*100;
        cout<<"Inflation rate: "<<setprecision(2)<<fixed<<infRate<<"%\n\n";
        
        //Choice to continue or stop, y or n
        cout<<"Again:\n";
        cin>>choice;
        if (choice=='n') break;
        cout<<endl;
    }while (choice=='y');

    //Exit stage right or left!
    return 0;
}