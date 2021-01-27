/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 26, 2021, 11:59 PM
 * Purpose: Time Converter
 */
 
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
void getInput (int&, int&);  //Gets Input
void convert  (int&, char&); //Converts Time
void output (int, int, int, char);  //Output

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    int iHrs, hrs, min;
    char type, choice;
    
    //Initialize Variables
    cout<<"Military Time Converter to Standard Time\n";
    cout<<"Input Military Time hh:mm\n";
    do{
        getInput(hrs, min);
        iHrs=hrs;  //Hour Before Conversion
        
        //Input Validation
        if ((hrs<=24&&hrs>=0)&&(min<=60&&min>=0)){
            
            //Map inputs to outputs
            convert(hrs, type);
            
            //Output Data
            output(iHrs, hrs, min, type);
            
        }else cout<<setprecision(2)<<hrs<<':'<<min<<" is not a valid time\n";
        
        //Choice to Start Over or End
        cout<<"Would you like to convert another time (y/n)\n";
        cin>>choice;
    }while (choice=='y'||choice=='Y');
    
    //Exit
    return 0;
}

void getInput (int &hrs, int &min){
    char colon;
    cin>>hrs>>colon>>min;
}

void convert  (int &hrs, char &type){
        if (hrs>12){
             hrs = hrs%12;
            type = 'P';
        }else if (hrs==12){
            type = 'P';
        }else if (hrs==0){
             hrs = 12;
            type = 'A';
        }else
            type = 'A';
}

void output (int iHrs, int hrs, int min, char type){
    cout<<setw(2)<<setfill('0')<<iHrs<<':'<<min<<" = ";
    cout<<hrs<<':'<<min<<' '<<type<<'M'<<endl;
}