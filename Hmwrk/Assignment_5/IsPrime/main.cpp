/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 26, 2021, 11:59 PM
 * Purpose:  Is Prime
 */

//System Libraries
#include <iostream>
using namespace std;

//Function Prototypes
bool isPrime(int);  //Determines if the input number is prime.

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int inp;
    bool prime;
    
    //Initialize Variables
    cout<<"Input a number to test if Prime.\n";
    cin>>inp;
    
    //Process/Map inputs to outputs
    prime=isPrime(inp);
    
    //Output data
    if (prime==true)  cout<<inp<<" is prime.";
    else if (prime==false) cout<<inp<<" is not prime.";
    
    //Exit stage right!
    return 0;
}

bool isPrime(int inp){
    bool prime=true;
    for(int i=2; i<=inp/2; i++){
        if (inp%i==0){
            prime=false;
            break;
        }
    }
    return prime;
}