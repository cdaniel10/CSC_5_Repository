/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 13, 2021, 12:36 PM
 * Purpose:  Diet Coke
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float CNVENGM = 453.592; //lbs to g

int main(int argc, char** argv) {

    //Declare Variables
    float massMs = 35,    //Mass of Mouse in Grams
         massKMs = 5,      //Mass of Sweetener to Kill Mouse in Grams
         mssCoke = 350,    //Mass of 1 Can of Diet Coke
          cncnt8 = 0.001f, //Concentration of Sweetener in a Can of Diet Coke
         wDieter;          //Weight of wDieter
    int    nCans;          //Number of Cans of Diet Coke
    
    //Map inputs -> outputs
    cout<<"Program to calculate the limit of Soda Pop Consumption.\n";
    cout<<"Input the desired dieters weight in lbs.\n";
    cin>>wDieter;
    
    nCans = (massKMs*wDieter*CNVENGM)/(massMs*mssCoke*cncnt8);
    
    //Display the outputs
    cout<<"The maximum number of soda pop cans\n";
    cout<<"which can be consumed is "<<nCans<<" cans";
  
    //Exit stage right or left!
    return 0;
}