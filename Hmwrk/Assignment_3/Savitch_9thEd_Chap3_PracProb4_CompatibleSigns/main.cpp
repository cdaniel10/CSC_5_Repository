/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 17, 2021, 11:59 PM
 * Purpose:  Compatible Signs
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {
    string sign1, sign2;
    
    //Map inputs -> outputs
    cout<<"Horoscope Program which examines compatible signs.\nInput 2 signs.\n";
    cin>>sign1>>sign2;
    
    //Fire
    if      ((sign1=="Aries" || sign1=="Leo"|| sign1=="Sagittarius")&&(sign2=="Aries" || sign2=="Leo" || sign2=="Sagittarius")){
        cout<<sign1<<" and "<<sign2<<" are compatible Fire signs.";}
        
    //Earth
    else if ((sign1=="Taurus" || sign1=="Virgo"|| sign1=="Capricorn")&&(sign2=="Taurus" || sign2=="Virgo" || sign2=="Capricorn")){
        cout<<sign1<<" and "<<sign2<<" are compatible Earth signs.";}
        
    //Air
    else if ((sign1=="Gemini" || sign1=="Libra"|| sign1=="Aquarius")&&(sign2=="Gemini" || sign2=="Libra" || sign2=="Aquarius")){
        cout<<sign1<<" and "<<sign2<<" are compatible Air signs.";}
        
    //Water
    else if ((sign1=="Cancer" || sign1=="Scorpio"|| sign1=="Pisces")&&(sign2=="Cancer" || sign2=="Scorpio" || sign2=="Pisces")){
        cout<<sign1<<" and "<<sign2<<" are compatible Water signs.";}
        
    //Not Compatible
    else cout<<sign1<<" and "<<sign2<<" are not compatible signs.";

    //Exit stage right or left!
    return 0;
}