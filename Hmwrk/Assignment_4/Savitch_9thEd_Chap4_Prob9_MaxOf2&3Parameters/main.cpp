/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 22, 2021, 12:36 PM
 * Purpose: Max of 2 and 3 Parameters
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    float frstNum, scndNum, thrdNum;
  
    //Inputs
    cout<<"Enter first number:\n\n";
    cin>>frstNum;  //First Number
    cout<<"Enter Second number:\n\n";
    cin>>scndNum;  //Second Number
    cout<<"Enter third number:\n\n";
    cin>>thrdNum;  //Third Number
    
    //Two Parameters
    float max(float frstNum, float scndNum);{
        cout<<"Largest number from two parameter function:\n";
        if (frstNum>scndNum){
            cout<<frstNum<<endl<<endl;
        }else cout<<scndNum<<endl<<endl;
    }
    
    //Three Parameters
    float max(float frstNum, float scndNum, float thrdNum);{
        cout<<"Largest number from three parameter function:\n";
        if (frstNum>scndNum&&frstNum>thrdNum){
            cout<<frstNum<<endl;
        }else if (scndNum>frstNum&&scndNum>thrdNum){
            cout<<scndNum<<endl;
        }else cout<<thrdNum<<endl;
    }

    //Exit stage right or left!
    return 0;
}