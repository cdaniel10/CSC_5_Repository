/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 22, 2021, 12:36 PM
 * Purpose:  Pattern
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {
    
    //Declare Variables
    unsigned short inp;
    char  plsSgn = '+';
    
    //Input
    cin>>inp;
    
    //Top Half of Pattern
    for(int i=0; i<inp; i++){
        for(int j=0; j<=i; j++){
            cout<<plsSgn;
        }
        cout<<endl<<endl;
    }
        
    //Bottom Half of Pattern    
    for(int i=0; i<inp; i++){
        for(int j=inp; j>i; j--){
            cout<<plsSgn;
        }
        if (i==(inp-1))break;
        cout<<endl<<endl;
    }
        
    //Exit stage right or left!
    return 0;
}