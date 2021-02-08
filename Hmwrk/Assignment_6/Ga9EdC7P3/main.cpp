/* 
 * File:   
 * Author: Christian Daniel
 * Created on: February 6th, 2021, 8:00PM
 * Purpose:  Salsa and Chips
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void displayData(string[],float[],float, int);
void findLowHigh (string[],float[],int,string&,string&);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const int SZE=5;  //Size of Arrays
    string salsa[SZE]={"mild", "medium", "sweet", "hot", "zesty"};  //5 Sauces
    float  sales[SZE];  //Sales From Each Product
    float totSls=0.0f;  //Total Sales
    string low, high;  //Lowest/Highest Selling Product
    
    //Initialize Variables
    for(int i=0; i<SZE; i++){
        cout<<"Enter the sales of "<<salsa[i]<<" salsa:$\n";
        cin>>sales[i];
    }
    
    //Process or map Inputs to Outputs
    displayData(salsa,sales,totSls,SZE);  //Display Sales
    findLowHigh (salsa,sales,SZE,low,high);  //Calculate Lowest and Highest Selling Product
    
    //Display Outputs
    cout<<low<<" was the lowest selling product.\n";
    cout<<high<<" was the highest selling product.";

    //Exit stage right!
    return 0;
}

void displayData(string salsa[],float sales[], float totSls,int SZE){
        cout<<"Type     Sales\n";
    for(int i=0; i<SZE; i++){
        cout<<setw(9)<<setfill(' ')<<left<<salsa[i]<<'$'<<setprecision(2)<<fixed<<sales[i]<<endl;
        totSls+=sales[i];
    }
    cout<<"Total Sales was $"<<setprecision(2)<<fixed<<totSls<<endl;
}

void findLowHigh (string salsa[],float sales[],int SZE,string &low ,string &high){
    //Initialize Variables
    float min=sales[0],
          max=sales[0];
    low=salsa[0];
    high=salsa[0];
    
    //Find Lowest
    for (int i=0;i<SZE;i++){
        if(sales[i]<min){
            min=sales[i];
            low=salsa[i];
        }
    }
    //Find Highest
    for (int i=0;i<SZE;i++){
        if(sales[i]>max){
            max=sales[i];
            high=salsa[i];
        }
    }
}