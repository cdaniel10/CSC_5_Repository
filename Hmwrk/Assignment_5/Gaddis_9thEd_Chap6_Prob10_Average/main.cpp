/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 26, 2021, 11:59 PM
 * Purpose: Average
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Function Prototypes
void getScre(int &,int &,int &,int &,int &);  //Gets Score
float calcAvg(int,int,int,int,int);  //Calculates Average of Top 4 Scores
int fndLwst(int,int,int,int,int);  //Finds lowest Score to Drop

//Execution Begins Here
int main(int argc, char** argv){
    
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