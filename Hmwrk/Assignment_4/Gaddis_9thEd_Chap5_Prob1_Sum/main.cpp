/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 22, 2021, 12:36 PM
 * Purpose:  Sum
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    unsigned short inp, sum=0;

    //Map inputs -> outputs
    cin>>inp;
    for(int i=1; i<=inp; i++){
        sum+=i;
    }
        
    //Display the outputs
    cout<<"Sum = "<<sum;
    
    //Exit stage right or left!
    return 0;
}