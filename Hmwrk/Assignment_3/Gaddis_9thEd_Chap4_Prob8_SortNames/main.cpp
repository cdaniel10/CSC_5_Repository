/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 17, 2021, 11:59 PM
 * Purpose: Sort Names
 */

#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {
    string n1, n2, n3;  //3 Names
    
    cout<<"Sorting Names\nInput 3 names\n";
    cin>>n1>>n2>>n3;
    
    //All Possible Arrangements Using First Letter of Each Name
    if      (n2[0]<n3[0] && n2[0]>n1[0]){
                cout<<n1<<'\n'<<n2<<'\n'<<n3;}
    else if (n3[0]<n2[0] && n3[0]>n1[0]){
                cout<<n1<<'\n'<<n3<<'\n'<<n2;}
    else if (n3[0]<n1[0] && n3[0]>n2[0]){
                cout<<n2<<'\n'<<n3<<'\n'<<n1;}
    else if (n1[0]<n3[0] && n1[0]>n2[0]){
                cout<<n2<<'\n'<<n1<<'\n'<<n3;}
    else if (n1[0]<n2[0] && n1[0]>n3[0]){
                cout<<n3<<'\n'<<n1<<'\n'<<n2;}
    else if (n2[0]<n1[0] && n2[0]>n3[0]){
                cout<<n3<<'\n'<<n2<<'\n'<<n1;}
    
    //Exit stage right or left!
    return 0;
}