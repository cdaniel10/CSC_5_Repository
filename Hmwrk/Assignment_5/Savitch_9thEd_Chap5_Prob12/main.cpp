/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 26, 2021, 11:59 PM
 * Purpose: Wait Time
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//Function Prototypes
void tAftrWtng(int &, int &, char &, int &);  //Calculates Time After Waiting

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    int hr, min, wTime;
    char type, choice;
    
    do{//Initialize or input i.e. set variable values
        cout<<"Enter hour:\n\n";
        cin>>hr;  //Hour
        cout<<"Enter minutes:\n\n";
        cin>>min; //Minutes
        cout<<"Enter A for AM, P for PM:\n\n";
        cin>>type; //AM or PM
        if (type=='p') type = 'P';
        if (type=='a') type = 'A';
        cout<<"Enter waiting time:\n\n";
        cin>>wTime; //Waiting Time
        
        //Output Current Time
        cout<<"Current time = "<<setw(2)<<setfill('0')<<hr<<':'
                    <<setw(2)<<setfill('0')<<min<<' '<<type<<'M'<<endl;
        
        //Calculate Time After Waiting
        tAftrWtng(hr, min, type, wTime);
        
        //Output Time After Waiting
        cout<<"Time after waiting period = "<<setw(2)<<setfill('0')<<hr<<':'
                    <<setw(2)<<setfill('0')<<min<<' '<<type<<'M'<<endl<<endl;
        
        //Choice to Input New Time or End 
        cout<<"Again:\n";
        cin>>choice;
        if (choice=='n'||choice=='N'){
            break;
        }
        cout<<endl;
    }while (choice=='y'||choice=='Y');

    //Exit stage right or left!
    return 0;
}

void tAftrWtng(int &hr, int &min, char &type, int &wTime){
    if (min+wTime>=60){
            hr += (min+wTime)/60;
            min = (min+wTime)%60; 
            if (hr>12){
                hr = hr%12;
                if  (type=='A'){
                     type = 'P';
                }else if (type=='P'){
                    type = 'A';
                }
            }else if (hr==12){
                if  (type=='A'){
                     type = 'P';
                }else if (type=='P'){
                    type = 'A';
                }
            }
    }else min += wTime;
}