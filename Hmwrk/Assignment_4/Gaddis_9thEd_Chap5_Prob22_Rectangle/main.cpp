/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 22, 2021, 12:36 PM
 * Purpose:  Rectangle
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    unsigned short inp;
    char        letter;
    
    //Input Number & Character
    cin>>inp>>letter;
    
    //Two Loops
    for(int i=1; i<inp+1; i++){    //Rows
        for(int i=0; i<inp; i++){  //Collums
            cout<<letter;
        }
        if(i<inp){
            cout<<endl;
        }
    }

    //Exit stage right or left!
    return 0;
}