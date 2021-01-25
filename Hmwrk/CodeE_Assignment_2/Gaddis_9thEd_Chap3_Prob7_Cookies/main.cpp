/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 12, 2021, 12:36 PM
 * Purpose  Cookies
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {
    
    //Declare Variables
    float ckiBag, //Cookies in bag
         servBag, //Servings per bag
         calServ, //Calories per serving
          ckiCal, //Calories for single cookie
         ckiCons, //Number of cookies consumed
         calCons; //Calories consumed
         
    //Initialize or input i.e. set variable values
    ckiBag  = 40;
    servBag = 10;
    calServ = 300;
    
    ckiCal  = calServ/(ckiBag/servBag); //Calories in one cookie
     
    //Map inputs -> outputs
    cout<<"Calorie Counter\n";
    cout<<"How many cookies did you eat?\n";
    cin>>ckiCons;
    
    //Display the outputs
    cout<<"You consumed "<<ckiCons*ckiCal<<" calories.";

    //Exit stage right or left!
    return 0;
}