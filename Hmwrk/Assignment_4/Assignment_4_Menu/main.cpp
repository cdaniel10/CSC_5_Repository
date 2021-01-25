/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 23, 2021, 11:59 PM
 * Purpose: Homework Menu Assignment 4
 */
//System Level Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Conversions
const float LTR2GAL=0.264179f;  //Number of Liters in a Gallon

int main(int argc, char** argv) {
    //Variable Declarations
    unsigned short choice;

    //Display Menu
    cout<<"Menu"<<endl;
    cout<<"Type 1 for Gaddis Sum Problem"<<endl;
    cout<<"Type 2 for Gaddis Pay in Pennies Problem"<<endl;
    cout<<"Type 3 for Gaddis Min Max Problem"<<endl;
    cout<<"Type 4 for Gaddis Rectangle Problem"<<endl;
    cout<<"Type 5 for Gaddis Pattern Problem"<<endl;
    cout<<"Type 6 for Savitch MPG Problem 1"<<endl;
    cout<<"Type 7 for Savitch MPG 2 Cars Problem 2"<<endl;
    cout<<"Type 8 for Savitch Inflation Rate Problem 4"<<endl;
    cout<<"Type 9 for Savitch Future Prices Problem 5"<<endl;
    cout<<"Type 10 for Savitch Max of 2 and 3 Parameters Problem 9"<<endl;
    
    cin>>choice;
    
    switch(choice){
        case 1:{
            //Declare Variables
            unsigned short inp, sum=0;

            //Map inputs -> outputs
            cin>>inp;
            for(int i=1; i<=inp; i++){
                sum+=i;
            }
            //Display the outputs
            cout<<"Sum = "<<sum;
            break;}
        case 2:{
            //Declare Variables
            unsigned short days;
            float dSalary=0.01f, total=0.00f;

            //Input
            do{
                cin>>days;    //Days worked
            }while(days<=0);  //Must Be More Than 0

            //Salary
            for(unsigned short i=1; i<=days; i++){
                total+=dSalary;
                 dSalary*=2;    //Salary Doubles Daily
            }

            //Display the outputs
            cout<<"Pay = $"<<total;
            break;}
        case 3:{
            //Declare Variables
            short int inp, max, min;

            //Initialize Variables
            cin>>inp;

            max=inp;
            min=inp;

            //Map inputs -> outputs
            while (true){
                //Input
                cin>>inp;

                //Exit Loop
                if (inp==-99) break;

                //Max and Min
                (inp>max)?max=inp:0;  //Find New Max
                (inp<min)?min=inp:0;  //Find New Min
            }
            cout<<"Smallest number in the series is "<<min<<endl;
            cout<<"Largest  number in the series is "<<max;            
            break;}
        case 4:{
            //Declare Variables
            unsigned short inp;
            char        letter;

            //Input Number & Character
            cin>>inp>>letter;

            //Two Loops
            for(int i=1; i<inp+1; i++){    //Rows
                for(int i=0; i<inp; i++){  //Collums
                    cout<<letter;
                }
                if(i<inp){
                    cout<<endl;
                }
            }
            break;}
        case 5:{
            //Declare Variables
            unsigned short inp;
            char  plsSgn = '+';

            //Input
            cin>>inp;

            //Top Half of Pattern
            for(int i=0; i<inp; i++){
                for(int j=0; j<=i; j++){
                    cout<<plsSgn;
                }
                cout<<endl<<endl;
            }

            //Bottom Half of Pattern    
            for(int i=0; i<inp; i++){
                for(int j=inp; j>i; j--){
                    cout<<plsSgn;
                }
                if (i==(inp-1))break;
                cout<<endl<<endl;
            }    
            break;}
        case 6:{
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
            break;}
        case 7:{
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
            break;}
        case 8:{
            //Declare Variables
            float crntP, oldP, infRate;
            char choice;

            //Map inputs -> outputs
            do{
                //Input
                cout<<"Enter current price:\n";
                cin>>crntP;  //Current Price
                cout<<"Enter year-ago price:\n";
                cin>>oldP;   //Last Years Price

                //Inflation Rate as Percent
                infRate = ((crntP-oldP)/oldP)*100;
                cout<<"Inflation rate: "<<setprecision(2)<<fixed<<infRate<<"%\n\n";

                //Choice to continue or stop, y or n
                cout<<"Again:\n";
                cin>>choice;
                if (choice=='n') break;
                cout<<endl;
            }while (choice=='y');
            break;}
        case 9:{
            //Declare Variables
            float crntP, oldP, infRate, infDec, oneYr, twoYr;
            char choice;

            //Map inputs -> outputs
            do{
                //Input
                cout<<"Enter current price:\n";
                cin>>crntP;  //Current Price
                cout<<"Enter year-ago price:\n";
                cin>>oldP;   //Last Years Price

                //Inflation Rate as Percent
                infRate = ((crntP-oldP)/oldP)*100;
                cout<<"Inflation rate: "<<setprecision(2)<<fixed<<infRate<<"%\n\n";

                //Inflation Rate as Decimal
                infDec= 1+infRate/100;

                //Future Prices
                oneYr=infDec*crntP;  //Price in One Year
                twoYr=infDec*oneYr;  //Price in Two Years
                cout<<"Price in one year: $"<<oneYr<<endl;
                cout<<"Price in two year: $"<<twoYr<<endl<<endl;

                //Choice to continue or stop, y or n
                cout<<"Again:\n";
                cin>>choice;
                if (choice=='n') break;
                cout<<endl;
            }while (choice=='y');
            break;}
        case 10:{
            //Declare Variables
            float frstNum, scndNum, thrdNum;

            //Inputs
            cout<<"Enter first number:\n\n";
            cin>>frstNum;  //First Number
            cout<<"Enter Second number:\n\n";
            cin>>scndNum;  //Second Number
            cout<<"Enter third number:\n\n";
            cin>>thrdNum;  //Third Number

            //Two Parameters
            float max(float frstNum, float scndNum);{
                cout<<"Largest number from two parameter function:\n";
                if (frstNum>scndNum){
                    cout<<frstNum<<endl<<endl;
                }else cout<<scndNum<<endl<<endl;
            }

            //Three Parameters
            float max(float frstNum, float scndNum, float thrdNum);{
                cout<<"Largest number from three parameter function:\n";
                if (frstNum>scndNum&&frstNum>thrdNum){
                    cout<<frstNum<<endl;
                }else if (scndNum>frstNum&&scndNum>thrdNum){
                    cout<<scndNum<<endl;
                }else cout<<thrdNum<<endl;
            }
            break;}
        
    } //End of Switch Case
 return 0;
}