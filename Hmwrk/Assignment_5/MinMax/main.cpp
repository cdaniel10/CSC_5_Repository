/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 26, 2021, 11:59 PM
 * Purpose:  Min-Max
 */

//System Libraries
#include <iostream>
using namespace std;

//Function Prototypes
void minmax(int,int,int,int&,int&);  //Function to find the min and max

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int num1, num2, num3, min, max;
    
    //Initialize Variables
    cout<<"Input 3 numbers\n";
    cin>>num1>>num2>>num3;
    
    minmax(num1, num2, num3, min, max);

    //Output data
    cout<<"Min = "<<min<<endl;
    cout<<"Max = "<<max;
    
    //Exit stage right!
    return 0;
}

void minmax(int num1, int num2, int num3, int &min, int &max){
    if       (num1>=num2&&num2>=num3){
        max=num1;
        min=num3;
    }else if (num1>=num3&&num3>=num2){
        max=num1;
        min=num2;
    }else if (num2>=num3&&num3>=num1){
        max=num2;
        min=num1;
    }else if (num2>=num1&&num1>=num3){
        max=num2;
        min=num3;
    }else if (num3>=num2&&num2>=num1){
        max=num3;
        min=num1;
    }else if (num3>=num1&&num1>=num2){
        max=num3;
        min=num2;
    }
}