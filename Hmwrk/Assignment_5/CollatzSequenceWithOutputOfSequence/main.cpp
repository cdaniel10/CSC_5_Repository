/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 26, 2021, 11:59 PM
 * Purpose: Collatz Sequence with Output of Sequence
 */

//System Libraries
#include <iostream>
using namespace std;

//Function Prototypes
int collatz(int);  //3n+1 sequence

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    int n, ns;
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl;
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    ns=collatz(n);  //Length of Sequence
    
    //Output data
    cout<<"\nSequence start of "<<n<<" cycles to 1 in "<<
            ns<<" steps";
    
    //Exit stage right!
    return 0;
}

int collatz(int n){
    //Declare/Initialize Variables
    int count=1;
    
    cout<<n;
        while (n != 1){
            if (n%2 == 1){
                n = (3*n)+1;
                count++;
            }else{
                n/=2,
                count++;
            }
        cout<<", "<<n;  //Output Sequence
        }
    return count;
}