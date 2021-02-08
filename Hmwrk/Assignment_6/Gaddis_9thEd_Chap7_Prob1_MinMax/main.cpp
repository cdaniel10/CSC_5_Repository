/* 
 * File: main.cpp
 * Author: Christian Daniel
 * Created on: February 6, 2021 5:00PM
 * Purpose:  Min Max
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int maximum(int[],int);
int minimum(int[],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    int ARYSZE=10;
    int x[ARYSZE];
    int max, min;

    //Initialize Variables
    cout<<"Enter 10 integers:\n";
    for (int i=0;i<10;i++){
        cin>>x[i];
    }
    //Process or map Inputs to Outputs
    max = maximum(x,ARYSZE);  //Find Max
    min = minimum(x,ARYSZE);  //Find Min
    
    //Display Outputs
    cout<<max<<" is the highest number.\n";
    cout<<min<<" is the lowest number.";
    
    //Exit stage right!
    return 0;
}

int maximum(int x[],int ARYSZE){
    int max=x[0];
    for (int i=1;i<ARYSZE;i++){
        if(x[i]>max){  //Compare to find Max
            max=x[i];
        }
    }
    return max;
}

int minimum(int x[],int ARYSZE){
    int min=x[0];
    for (int i=1;i<ARYSZE;i++){
        if(x[i]<min){  //Compare to find Min
            min=x[i];
        }
    }
    return min;
}