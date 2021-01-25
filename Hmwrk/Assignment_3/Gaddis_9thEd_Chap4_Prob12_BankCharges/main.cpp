/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 17, 2019, 11:59 PM
 * Purpose:  Bank Charges
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    float   begBlnc, //Beginning Balance
            numChks, //Number of Checks
             chkFee, //Check Fee
             lowFee, //Low Balance Fee
              nBlnc, //New Balance
             monFee; //Monthly Fee

    //Map inputs -> outputs
    cout<<"Monthly Bank Fees\nInput Current Bank Balance and Number of Checks\n";
    cin>>begBlnc>>numChks;
    
    if (numChks>=0){
        
        chkFee = (numChks<20)?0.10:  //Check Fee in USD
                 (numChks<40)?0.08:
                 (numChks<60)?0.06:0.04;

        lowFee = (begBlnc>=400)?0.00:15.00; //Low Balance Fee in USD

        monFee = 10.00; //Monthly Fee in USD

        nBlnc = begBlnc-(chkFee*numChks)-lowFee-monFee; //Balance minus Fees

        //Display the outputs
        cout<<"Balance     $"<<setw(9)<<setprecision(2)<<fixed<<begBlnc<<endl;
        cout<<"Check Fee   $"<<setw(9)<<setprecision(2)<<fixed<<chkFee*numChks<<endl;
        cout<<"Monthly Fee $"<<setw(9)<<setprecision(2)<<fixed<<monFee<<endl;
        cout<<"Low Balance $"<<setw(9)<<setprecision(2)<<fixed<<lowFee<<endl;
        cout<<"New Balance $"<<setw(9)<<setprecision(2)<<fixed<<nBlnc;
        
        if (begBlnc<0){
            cout<<"\nUrgent Message: Your Account is Overdrawn.";
        }
    }

    //Exit stage right or left!
    return 0;
}