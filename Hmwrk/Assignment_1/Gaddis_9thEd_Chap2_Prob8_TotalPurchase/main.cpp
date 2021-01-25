/* 
 * File:   main.cpp
 * Author: Christian Daniel
 *
 * Created on January 10, 2021, 11:59 PM
 * Purpose: Total Purchase
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
    float item_1, item_2, item_3, item_4, item_5, tax, taxAmnt, subtotl, total;
    int itax;
    
    //Initialize Variables
    item_1=15.95;   //Price of the 5 items Purchased in USD
    item_2=24.95;
    item_3= 6.95;
    item_4=12.95;
    item_5= 3.95;
     
    tax=0.07;       //Percent Tax
            
    //Map Inputs to Outputs -> Process    
    subtotl=item_1+item_2+item_3+item_4+item_5; //Subtotal
    
    itax=(subtotl*tax+0.005)*100;  //Tax Amount*100 as Integer
    taxAmnt= (itax/100.00);        //Tax Amount with 2 Decimal Places
    total=taxAmnt+subtotl;         //Total
        
    //Display Inputs/Outputs
    cout<<"Price of Item 1: $"<<item_1<<endl;
    cout<<"Price of Item 2: $"<<item_2<<endl;
    cout<<"Price of Item 3:  $"<<item_3<<endl;
    cout<<"Price of Item 4: $"<<item_4<<endl;
    cout<<"Price of Item 5:  $"<<item_5<<'\n'<<endl;
    cout<<"Subtotal:        $"<<subtotl<<endl;
    cout<<"Tax:              $"<<taxAmnt<<'\n'<<endl;
    cout<<"Total:           $"<<total<<endl;

    //Exit the Program - Cleanup
    return 0;
}