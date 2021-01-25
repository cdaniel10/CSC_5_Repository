/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 17, 2021, 11:59 PM
 * Purpose:  ISP
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    char pack;
    unsigned short hours;
    float bill;

    //Map inputs -> outputs
    cout<<"ISP Bill\nInput Package and Hours\n";
    cin>>pack>>hours;
    
    if       (pack=='A'){
        bill = (hours<=10) ? 9.95 : (hours-10)*2.00+9.95;   //$9.95/month plus $2/every additional hour after 10
        cout<<"Bill = $"<<setw(6)<<setprecision(2)<<fixed<<bill;
    }else if (pack=='B'){
        bill = (hours<=20) ? 14.95 : (hours-20)*1.00+14.95; //$14.95/month plus $1/every additional hour after 20
        cout<<"Bill = $"<<setw(6)<<setprecision(2)<<fixed<<bill;
    }else if (pack=='C'){
        bill = 19.95;                                       //$19.95/month
        cout<<"Bill = $"<<setw(6)<<setprecision(2)<<fixed<<bill;
    }

    //Exit stage right or left!
    return 0;
}