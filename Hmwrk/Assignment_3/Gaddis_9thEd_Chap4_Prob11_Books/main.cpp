/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 17, 2021, 11:59 PM
 * Purpose:  Books
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    unsigned short numBook, ptsEarn; //Number of Books Purchased & Points Earned

    //Map inputs -> outputs
    cout<<"Book Worm Points\nInput the number of books purchased this month.\n";
    cin>>numBook;
    
    ptsEarn = (numBook==0)? 0:
              (numBook==1)? 5:
              (numBook==2)?15:
              (numBook==3)?30:60;
    
    //Display the outputs
    cout<<"Books purchased ="<<setw(3)<<numBook<<endl;
    cout<<"Points earned   ="<<setw(3)<<ptsEarn;
    
    //Exit stage right or left!
    return 0;
}