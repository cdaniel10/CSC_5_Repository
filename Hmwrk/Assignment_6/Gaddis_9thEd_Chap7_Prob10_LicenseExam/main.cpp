/* 
 * File: main.cpp
 * Author: Christian Daniel
 * Created on: February 6th, 2021, 7:00PM
 * Purpose: Driver's License Exam
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
bool grade(char[],int,int [],int&);
void display(int[],int,int,bool);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    int SZE=20;  //Number of Exam Questions
    char x[SZE];  //Students Answers
    int wrng[SZE];  //Wrong Problem Numbers
    int numWrng=0;  //Number of Wrong Answers
    bool pass;  //Pass or Fail
    
    //Initialize Variables
    cout<<"Enter the student's test answers:\n";
    for (int i=0;i<SZE;i++){
        cin>>x[i];
    }
    //Process or map Inputs to Outputs
    pass=grade(x,SZE,wrng,numWrng);
    
    //Display Outputs
    display(wrng,SZE,numWrng,pass);

    //Exit stage right!
    return 0;
}

void display(int wrng[],int SZE, int numWrng, bool pass){
    cout<<"The student ";
    (pass==true)?cout<<"passed.\n":cout<<"failed.\n";
    cout<<"There were "<<SZE-numWrng<<" correct answers.\n";
    cout<<"There were "<<numWrng<<" incorrect answers.\n";
    cout<<"Incorrect questions:\n";
    for(int i=0;i<numWrng;i++){  //Output All Wrong Problem Numbers
        cout<<wrng[i]<<endl;
    }
}

bool grade(char x[],int SZE,int wrng[], int &numWrng){
    bool pass;
    char ans[]={'A','D','B','B','C','B','A','B','C','D',  //Answer Key
                'A','C','D','B','D','C','C','A','D','B'};
    for(int i=0; i<SZE;i++){  
        if (!(x[i]==ans[i])){  //Compares Each Problem to Answer Key
            wrng[numWrng]=i+1;  //Records Problem Number of Wrong Answers
            numWrng++;  //Add 1 to Wrong Answer Count
        }
    }
    if (numWrng>5) pass=false;  //Needs At Least 15/20 Correct to Pass
    return pass;
}