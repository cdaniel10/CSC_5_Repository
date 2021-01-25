/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 17, 2021, 11:59 PM
 * Purpose:  Race
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    string         name1, name2, name3,  first,  second,  third;
    unsigned short time1, time2, time3, tFirst, tSecond, tThird;

    //Map inputs -> outputs
    cout<<"Race Ranking Program\n";
    cout<<"Input 3 Runners\n";
    cout<<"Their names, then their times\n";
    cin>>name1>>time1;
    cin>>name2>>time2;
    cin>>name3>>time3;
    
    //All Possible Arrangements
    if (time2<time3 && time2>time1){
        first  = name1;
        second = name2;
        third  = name3;
        tFirst  = time1;
        tSecond = time2;
        tThird  = time3;
    }else if (time3<time3 && time3>time2){
        first  = name2;
        second = name3;
        third  = name1;
        tFirst  = time2;
        tSecond = time3;
        tThird  = time1;
    }else if (time1<time2 && time1>time3){
        first  = name3;
        second = name1;
        third  = name2;
        tFirst  = time3;
        tSecond = time1;
        tThird  = time2;
    }else if (time3<time2 && time3>time1){
        first  = name1;
        second = name3;
        third  = name2;
        tFirst  = time1;
        tSecond = time3;
        tThird  = time2;
    }else if (time1<time3 && time1>time2){
        first  = name2;
        second = name1;
        third  = name3;
        tFirst  = time2;
        tSecond = time1;
        tThird  = time3;
    }else if (time2<time1 && time2>time3){
        first  = name3;
        second = name2;
        third  = name1;
        tFirst  = time3;
        tSecond = time2;
        tThird  = time1;
    }
    //Display the outputs
    cout<<first <<'\t'<<setw(3)<<tFirst<<endl;
    cout<<second<<'\t'<<setw(3)<<tSecond<<endl;
    cout<<third <<'\t'<<setw(3)<<tThird;
    
    //Exit stage right or left!
    return 0;
}