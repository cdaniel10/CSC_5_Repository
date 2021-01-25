/* 
 * File:   main.cpp
 * Author: Christian Daniel
 *
 * Created on January 10, 2021, 11:59 PM
 * Purpose: Restaurant Bill
 */

// System Libraries
#include <iostream>  //I/O Library
using namespace std;

//Users Libraries
//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays
//Function Prototypes
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed    
    //Declare Variables
    float mealCst, //Cost of Meal in USD
              tax, //% tax
              tip, //% tip
          totBill, // Total Bill After Tax and Tip in USD
          taxAmnt, //Tax Amount in USD
          tipAmnt; //Tip Amount in USD
    int      itax, //Tax Amount*100
             itip; //Tip Amount*100
    
    //Initialize Variables
    mealCst=88.67;
    tax=.0675;
    tip=.2;
            
    //Map Inputs to Outputs -> Process
    itax=(mealCst*tax+0.005)*100; //Tax Amount*100 as Integer
    taxAmnt=itax/100.00;          //Tax Amount as Float with 2 decimal places
    
    itip=((mealCst+taxAmnt)*tip+0.005)*100;//Tip Amount*100 as Integer
    tipAmnt=itip/100.00;          //Tip Amount as Float with 2 decimal places
    
    totBill=mealCst+taxAmnt+tipAmnt; //Meal Cost + Tax + Tip (USD)
    
    //Display Inputs/Outputs
    cout<<"Meal:   $"<<mealCst<<endl;
    cout<<"Tax:     $"<<taxAmnt<<endl;
    cout<<"Tip:    $"<<tipAmnt<<'\n'<<endl;
    cout<<"Total: $"<<totBill<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}