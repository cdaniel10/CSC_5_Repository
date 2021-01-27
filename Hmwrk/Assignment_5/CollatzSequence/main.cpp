/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 26, 2021, 11:59 PM
 * Purpose:  Collatz Sequence
 */

//System Libraries
#include <iostream>
using namespace std;

//Function Prototypes
int collatz(int);  //3n+1 sequence

//Execution Begins Here
int main(int argc, char** argv){
    
    //Declare Varibles
    int n;
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl;
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Output
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            collatz(n)<<" steps";
    
    //Exit stage right!
    return 0;
}

int collatz(int n){
    int count=1;
        while (n != 1){
            if (n%2 == 1){
                n = (3*n)+1;
                count++;
            }else{
                n/=2,
                count++;
        }
    }
    return count;
}