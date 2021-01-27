/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 26, 2021, 11:59 PM
 * Purpose: Assignment 5 Menu
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Function Prototypes
int minMax();
int factorial();
int prime();
int collatzSeq();
int collatzSeqWOut();
int waitTime();
int timeConverter();
int presentValue();
int average();

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Variable Declarations
    char choice;

    //Display Menu
    cout<<"Menu"<<endl;
    cout<<"Type 1 for Min Max Problem"<<endl;
    cout<<"Type 2 for Factorial Problem"<<endl;
    cout<<"Type 3 for Is Prime Problem"<<endl;
    cout<<"Type 4 for Collatz Sequence Problem"<<endl;
    cout<<"Type 5 for Collatz Sequence With Output of Sequence Problem"<<endl;
    cout<<"Type 6 for Savitch Waiting Time Problem 12"<<endl;
    cout<<"Type 7 for Savitch Time Converter Problem 1"<<endl;
    cout<<"Type 8 for Gaddis Present Value Problem 9"<<endl;
    cout<<"Type 9 for Gaddis Average Problem 10"<<endl;
    cin>>choice;
    
    switch(choice){
        case '1':{minMax();
            break;}
        case '2':{factorial();
            break;}
        case '3':{prime();
            break;}
        case '4':{collatzSeq();
            break;}
        case '5':{collatzSeqWOut();
            break;}
        case '6':{waitTime();
            break;}
        case '7':{timeConverter();
            break;}
        case '8':{presentValue();
            break;}
        case '9':{average();
         break;}
        
    }
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                 Min Max
//Inputs:
//     num# -> 3 Numbers
//
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

//Function Prototypes
void calcMinMax(int,int,int,int&,int&);  //Function to find the min and max

//Execution Begins Here
int minMax(){
    //Declare Variables
    int num1, num2, num3, min, max;
    
    //Initialize Variables
    cout<<"Input 3 numbers\n";
    cin>>num1>>num2>>num3;
    
    calcMinMax(num1, num2, num3, min, max);

    //Output data
    cout<<"Min = "<<min<<endl;
    cout<<"Max = "<<max;
    
    //Exit stage right!
    return 0;
}

void calcMinMax(int num1, int num2, int num3, int &min, int &max){
    if       (num1>=num2&&num2>=num3){
        max=num1;
        min=num3;
    }else if (num1>=num3&&num3>=num2){
        max=num1;
        min=num2;
    }else if (num2>=num3&&num3>=num1){
        max=num2;
        min=num1;
    }else if (num2>=num1&&num1>=num3){
        max=num2;
        min=num3;
    }else if (num3>=num2&&num2>=num1){
        max=num3;
        min=num1;
    }else if (num3>=num1&&num1>=num2){
        max=num3;
        min=num2;
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Factorial
//Inputs:
//      n -> Number
//      
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

//Function Prototypes
int fctrl(int);  //Function to Calculate Factorial

//Execution Begins Here
int factorial(){
    //Declare Variables
    int n;

    //Process/Map inputs to outputs
    cout<<"This program calculates the factorial using a function prototype "
          "found in the template for this problem.\n";
    cout<<"Input the number for the function.\n";
    cin>>n;
    
    //Output data
    cout<<n<<"! = "<<fctrl(n);
    
    //Exit stage right!
    return 0;
}

int fctrl(int n){
    if(n > 1) return n*fctrl(n - 1);
    else return 1;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Is Prime
//Inputs:
//      inp -> Number
//      
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

//Function Prototypes
bool isPrime(int);  //Determines if the input number is prime.

//Execution Begins Here
int prime(){
    //Declare Variables
    int inp;
    bool prime;
    
    //Initialize Variables
    cout<<"Input a number to test if Prime.\n";
    cin>>inp;
    
    //Process/Map inputs to outputs
    prime=isPrime(inp);
    
    //Output data
    if (prime==true)  cout<<inp<<" is prime.";
    else if (prime==false) cout<<inp<<" is not prime.";
    
    //Exit stage right!
    return 0;
}

bool isPrime(int inp){
    bool prime=true;
    for(int i=2; i<=inp/2; i++){
        if (inp%i==0){
            prime=false;
            break;
        }
    }
    return prime;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                             Collatz Sequence
//Inputs:
//      n -> Number
//      
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

//Function Prototypes
int collatz(int);  //3n+1 sequence

//Execution Begins Here
int collatzSeq(){
    
    //Declare Varibles
    int n;
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl;
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Output
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            collatz(n)<<" steps";
    
    //Exit stage right!
    return 0;
}

int collatz(int n){
    int count=1;
        while (n != 1){
            if (n%2 == 1){
                n = (3*n)+1;
                count++;
            }else{
                n/=2,
                count++;
        }
    }
    return count;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                    Collatz Sequence With Sequence Output
//Inputs:
//      n -> Number
//      
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

//Function Prototypes
int clltz(int);  //3n+1 sequence

//Execution Begins Here
int collatzSeqWOut(){
    
    //Declare Variables
    int n, ns;
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl;
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    ns=clltz(n);  //Length of Sequence
    
    //Output data
    cout<<"\nSequence start of "<<n<<" cycles to 1 in "<<
            ns<<" steps";
    
    //Exit stage right!
    return 0;
}

int clltz(int n){
    //Declare/Initialize Variables
    int count=1;
    
    cout<<n;
        while (n != 1){
            if (n%2 == 1){
                n = (3*n)+1;
                count++;
            }else{
                n/=2,
                count++;
            }
        cout<<", "<<n;  //Output Sequence
        }
    return count;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Wait Time
//Inputs:
//      hr -> Hour
//     min -> Minutes
//    type -> AM/PM
//   wTime -> Wait Time
//      
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

//Function Prototypes
void tAftrWtng(int &, int &, char &, int &);  //Calculates Time After Waiting

//Execution Begins Here!
int waitTime(){

    //Declare Variables
    int hr, min, wTime;
    char type, choice;
    
    do{//Initialize or input i.e. set variable values
        cout<<"Enter hour:\n\n";
        cin>>hr;  //Hour
        cout<<"Enter minutes:\n\n";
        cin>>min; //Minutes
        cout<<"Enter A for AM, P for PM:\n\n";
        cin>>type; //AM or PM
        if (type=='p') type = 'P';
        if (type=='a') type = 'A';
        cout<<"Enter waiting time:\n\n";
        cin>>wTime; //Waiting Time
        
        //Output Current Time
        cout<<"Current time = "<<setw(2)<<setfill('0')<<hr<<':'
                    <<setw(2)<<setfill('0')<<min<<' '<<type<<'M'<<endl;
        
        //Calculate Time After Waiting
        tAftrWtng(hr, min, type, wTime);
        
        //Output Time After Waiting
        cout<<"Time after waiting period = "<<setw(2)<<setfill('0')<<hr<<':'
                    <<setw(2)<<setfill('0')<<min<<' '<<type<<'M'<<endl<<endl;
        
        //Choice to Input New Time or End 
        cout<<"Again:\n";
        cin>>choice;
        if (choice=='n'||choice=='N'){
            break;
        }
        cout<<endl;
    }while (choice=='y'||choice=='Y');

    //Exit stage right or left!
    return 0;
}

void tAftrWtng(int &hr, int &min, char &type, int &wTime){
    if (min+wTime>=60){
            hr += (min+wTime)/60;
            min = (min+wTime)%60; 
            if (hr>12){
                hr = hr%12;
                if  (type=='A'){
                     type = 'P';
                }else if (type=='P'){
                    type = 'A';
                }
            }else if (hr==12){
                if  (type=='A'){
                     type = 'P';
                }else if (type=='P'){
                    type = 'A';
                }
            }
    }else min += wTime;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                             Time Converter
//Inputs:
//     hrs -> Hour
//     min -> Minutes
//      
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

//Function Prototypes
void getInput (int&, int&);  //Gets Input
void convert  (int&, char&); //Converts Time
void output (int, int, int, char);  //Output

//Execution Begins Here!
int timeConverter(){
    
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
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                             Present Value
//Inputs:
//      fv -> Future Value in USD
//     yrs -> Years
//   iRate -> Interest Rate %/yr
//      
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

//Function Prototypes
float psntVal(float, float, int);  //Calculates Present Value

//Execution Begins Here
int presentValue(){
    
    //Declare Variables
    float fv, yrs, pv;
    int iRate;
    
    //Initialize Variables
    cout<<"This is a Present Value Computation\n";
    cout<<"Input the Future Value in Dollars\n";
    cin>>fv;  //Future Value in USD
    cout<<"Input the Number of Years\n";
    cin>>yrs;  //Number of Years
    cout<<"Input the Interest Rate %/yr\n";
    cin>>iRate; //Interest Rate
    
    //Map Inputs -> Outputs
    pv = psntVal(fv, yrs, iRate);  //Present Value
    
    //Output Data
    cout<<"The Present Value = $"<<setprecision(2)<<fixed<<pv;
    
    //Exit
    return 0;
}

float psntVal(float fv, float yrs, int iRate){
    return (fv/(pow(1+(iRate/100.),yrs)))+.005;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                             Average
//Inputs:
//     sc# -> 5 Scores
//      
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

//Function Prototypes
void getScre(int &,int &,int &,int &,int &);  //Gets Score
float calcAvg(int,int,int,int,int);  //Calculates Average of Top 4 Scores
int fndLwst(int,int,int,int,int);  //Finds lowest Score to Drop

//Execution Begins Here
int average(){
    
    //Declare Variables
    int sc1, sc2, sc3, sc4, sc5;  //5 Scores
    
    //Process/Map inputs to outputs
    getScre(sc1, sc2, sc3, sc4, sc5);  //Input
    calcAvg(sc1, sc2, sc3, sc4, sc5);  //Calculate and Output
    
    //Exit 
    return 0;
}

void getScre(int &sc1,int &sc2,int &sc3,int &sc4,int &sc5){
    cout<<"Find the Average of Test Scores\n";
    cout<<"by removing the lowest value.\n";
    cout<<"Input the 5 test scores.\n";
    cin>>sc1>>sc2>>sc3>>sc4>>sc5;
}

float calcAvg(int sc1, int sc2, int sc3, int sc4, int sc5){
    
    //Declare Variables
    int lwst;
    float avg;
    
    //Initialize Variables
    lwst = fndLwst(sc1, sc2, sc3, sc4, sc5);  //Lowest Number
    avg = (sc1+sc2+sc3+sc4+sc5-lwst)/4;  //Top 4 Average
    
    //Output
    cout<<"The average test score = "<<setprecision(1)<<fixed<<avg;
    return avg;
}

int fndLwst(int sc1, int sc2, int sc3, int sc4, int sc5){
    if       (sc1<sc2&&sc1<sc3&&sc1<sc4&&sc1<sc5){
        return sc1;
    }else if (sc2<sc1&&sc2<sc3&&sc2<sc4&&sc2<sc5){
        return sc2;
    }else if (sc3<sc1&&sc3<sc2&&sc3<sc4&&sc3<sc5){
        return sc3;
    }else if (sc4<sc1&&sc4<sc2&&sc4<sc3&&sc4<sc5){
        return sc4;
    }else if (sc5<sc1&&sc5<sc2&&sc5<sc3&&sc5<sc4){
        return sc5;
    }
}