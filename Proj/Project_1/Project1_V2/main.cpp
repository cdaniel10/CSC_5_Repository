/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on February 3rd, 2020, 11:00 PM
 * Purpose:  Battleship
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short   fire,
                    tries=0, //Number of Guesses
                    ship1=3, //Computer Ship 1
                    ship2=8; //Computer Ship 2
    bool s1=true, //Ship 1 floating or sunk
         s2=true; //Ship 2 floating or sunk
    
    //Initialize Variables
    do{
        do{
        cout<<"Fire at: A"; //Fire at A#
            cin>>fire;
            if (fire<1||fire>10){  //If Input is not 1-10
                cout<<"Invalid! Input Number 1-10"<<endl;  //Output Message
            }
        }while (fire<1||fire>10);  //Input Validation
        
        //Map Inputs to Outputs -> Process
        tries++;  //Add 1 to Guess Count
        if (fire==ship1){  //Did Ship 1 Get Hit
            cout<<"HIT!";  //Output "Hit" If Ship 1 is hit
            s1=false;  //Set s1 to false (sunk)
        }else if (fire==ship2){  //Did Ship 2 Get Hit
            cout<<"HIT!";  //Output "Hit" If Ship 2 is hit
            s2=false;  //Set s2 to false (sunk)
        }else cout<<"MISS!";  //Output "Miss" If No Ships Were Hit
        cout<<endl;  //Next line
    }while (tries<=10&&(s1==true||s2==true));  //Keep looping until win or lose
    
    //Output W/L
    if (s1==false&&s2==false){  //If All Ships Are Sunk Output "You Win"
        cout<<"You Win";
    }else cout<<"You Lose";  //If Guesses Exceed 10 or If Ships remain, Output "You lose"
    
    //Exit stage right!
    return 0;
}
