/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 22, 2021, 12:36 PM
 * Purpose:  MPG
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//Conversions
const float LTR2GAL=0.264179f;  //Number of Liters in a Gallon

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    float numLitr, miles, mpg;
    char  choice;

    //Map inputs -> outputs
    do{
        //Input
        cout<<"Enter number of liters of gasoline:\n"<<endl;
        cin>>numLitr;  //Number of Liters
        cout<<"Enter number of miles traveled:\n"<<endl;;
        cin>>miles;    //Number of Miles
        
        //Miles Per Gallon using Global Constant
        mpg = miles/(numLitr*LTR2GAL);
        cout<<"miles per gallon:\n";
        cout<<setprecision(2)<<fixed<<mpg<<endl;
        
        //Choice to continue or stop, y or n
        cout<<"Again:\n";
        cin>>choice;  
        if (choice=='n' || choice=='N')break;
        cout<<endl;
    }while(choice=='y' || choice=='Y');

    //Exit stage right or left!
    return 0;
}