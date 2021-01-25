/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 22, 2021, 12:36 PM
 * Purpose:  MPG For Two Cars
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
    float numLitr, miles, mpg1, mpg2;
    char choice;

    //Map inputs -> outputs
    do{
        //Car 1
        cout<<"Car 1\n";
        cout<<"Enter number of liters of gasoline:\n";
        cin>>numLitr;  //Number of Liters
        cout<<"Enter number of miles traveled:\n";
        cin>>miles;    //Number of Miles
        
        //MPG of Car 1
        mpg1 = miles/(numLitr*LTR2GAL);
        cout<<"miles per gallon: ";
        cout<<setprecision(2)<<fixed<<mpg1<<endl<<endl;
        
        //Car 2
        cout<<"Car 2\n";
        cout<<"Enter number of liters of gasoline:\n";
        cin>>numLitr;  //Number of Liters
        cout<<"Enter number of miles traveled:\n";
        cin>>miles;    //Number of Miles
        
        //MPG of Car 2
        mpg2 = miles/(numLitr*LTR2GAL);
        cout<<"miles per gallon: ";
        cout<<setprecision(2)<<fixed<<mpg2<<endl<<endl;
        
        //Most Feul Efficient
        (mpg1>mpg2)?cout<<"Car 1 is more fuel efficient\n\n":
                    cout<<"Car 2 is more fuel efficient\n\n";
        
        //Choice to continue or stop, y or n
        cout<<"Again:\n";
        cin>>choice;
        if (choice=='n') break;
        cout<<endl;
    }
    while (choice=='y');
        
    //Exit stage right or left!
    return 0;
}