/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 13, 2021, 12:36 PM
 * Purpose:  Pay
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    unsigned short anualSl;
    float          pyRaise,
                   rtroPay,
                   nAnualS,
                   nMnthyS;
    
    //Initialize or input i.e. set variable values
    pyRaise = .076;  //% Pay Increase
    
    //Map inputs -> outputs
    cout<<"Input previous annual salary.\n";
    cin>>anualSl;
    
    rtroPay = (anualSl/2)*pyRaise;
    nAnualS = anualSl*(pyRaise+1);
    nMnthyS = nAnualS/12;
    
    //Display the outputs
    cout<<"Retroactive pay    = $"<<setw(7)<<setprecision(2)<<fixed<<rtroPay<<endl;
    cout<<"New annual salary  = $"<<setw(7)<<setprecision(2)<<fixed<<nAnualS<<endl;
    cout<<"New monthly salary = $"<<setw(7)<<setprecision(2)<<fixed<<nMnthyS;
    
    //Exit stage right or left!
    return 0;
}