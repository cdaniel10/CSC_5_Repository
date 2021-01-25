/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 17, 2021, 11:59 PM
 * Purpose:  Rock Paper Scissors
 */
//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    char p1, p2;  //Player 1 and Player 2
    
    //Map inputs -> outputs
    cout<<"Rock Paper Scissors Game\nInput Player 1 and Player 2 Choices\n";
    cin>>p1>>p2;
    
    //Nobody Wins
    if      ((p1=='R' || p1=='r')&&(p2=='R' || p2=='r')){
        cout<<"Nobody wins.";}
    else if ((p1=='P' || p1=='p')&&(p2=='P' || p2=='p')){
        cout<<"Nobody wins.";}
    else if ((p1=='S' || p1=='s')&&(p2=='S' || p2=='s')){
        cout<<"Nobody wins.";}
    
    //Paper Wins
    else if ((p1=='R' || p1=='r')&&(p2=='P' || p2=='p')){
        cout<<"Paper covers rock.";}
    else if ((p1=='P' || p1=='p')&&(p2=='R' || p2=='r')){
        cout<<"Paper covers rock.";}
    
    //Rock Wins
    else if ((p1=='R' || p1=='r')&&(p2=='S' || p2=='s')){
        cout<<"Rock breaks scissors.";}
    else if ((p1=='S' || p1=='s')&&(p2=='R' || p2=='r')){
        cout<<"Rock breaks scissors.";}
    
    //Scissors Win
    else if ((p1=='P' || p1=='p')&&(p2=='S' || p2=='s')){
        cout<<"Scissors cuts paper.";}
    else if ((p1=='S' || p1=='s')&&(p2=='P' || p2=='p')){
        cout<<"Scissors cuts paper.";}

    //Exit stage right or left!
    return 0;
}