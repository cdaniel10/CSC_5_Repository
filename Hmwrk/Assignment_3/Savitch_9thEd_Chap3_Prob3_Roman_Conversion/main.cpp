/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 17, 2021, 11:59 PM
 * Purpose:  Roman Conversion
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    unsigned short n2Cnvrt;  //Number to Convert
    
    //Initialize or input i.e. set variable values
    cout<<"Arabic to Roman numeral conversion.\nInput the integer to convert.\n";
    cin>>n2Cnvrt;
    
    //Map inputs -> outputs
    if (n2Cnvrt>=1000 && n2Cnvrt<=3000){  //Input Must Be Between 1000 and 3000
        cout<<n2Cnvrt<<" is equal to ";
        
        //Determine 1000s, 100s, 10s, 1s
        unsigned char n1000s, n100s, n10s, n1s;
        n1000s = n2Cnvrt/1000;
        n100s  = n2Cnvrt%1000/100;
        n10s   = n2Cnvrt%100/10;
        n1s    = n2Cnvrt%10;
        
        //Output the Number of 1000s
        switch (n1000s){
            case 3:cout<<'M';
            case 2:cout<<'M';
            case 1:cout<<'M';}
        
        //Output the Number of 100s
        cout<<(n100s==9?"CM":
               n100s==8?"DCCC":
               n100s==7?"DCC":
               n100s==6?"DC":
               n100s==5?"D":
               n100s==4?"CD":
               n100s==3?"CCC":
               n100s==2?"CC":
               n100s==1?"C":"");
        
        //Output the Number of 10s
        cout<<(n10s==9?"XC":
               n10s==8?"LXXX":
               n10s==7?"LXX":
               n10s==6?"LX":
               n10s==5?"L":
               n10s==4?"XL":
               n10s==3?"XXX":
               n10s==2?"XX":
               n10s==1?"X":"");
               
        //Output the Number of 1s
        cout<<(n1s==9?"IX":
               n1s==8?"VIII":
               n1s==7?"VII":
               n1s==6?"VI":
               n1s==5?"V":
               n1s==4?"IV":
               n1s==3?"III":
               n1s==2?"II":
               n1s==1?"I":"");
               
    }else cout<<n2Cnvrt<<" is Out of Range!";

    //Exit stage right or left!
    return 0;
}