/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on February 3rd, 2020, 11:00 PM
 * Purpose:  Battleship
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>
#include <ctime>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variable Data Types and Constants
    unsigned short   fire,  //Location To Fire At
                    cFire,  //Location Opponent Fires At
                    tries=0, //Number of Guesses
                    ship1,  //Ship 1 Location
                    ship2,  //Ship 2 Location
                    cShip1=rand()%10+1, //Opponent Ship 1
                    cShip2=rand()%10+1; //Opponent Ship 2
    bool s1=true, //Ship 1 floating or sunk
         s2=true, //Ship 2 floating or sunk
         cS1=true, //Opponent Ship 1 floating or sunk
         cS2=true; //Opponent Ship 2 floating or sunk
    
    //Initialize Variables
    do{  //Input Ships Location
        cout<<"Place Ship 1 at: A";
        cin>>ship1;
        cout<<"Place Ship 2 at: A";
        cin>>ship2;
        if ((ship1<1||ship1>10)||(ship2<1||ship2>10)){  //Input Validation
            cout<<"Invalid! Input Number 1-10 for both ships."<<endl;
        }
    }while ((ship1<1||ship1>10)||(ship2<1||ship2>10));  //Loop Until Inputs Are Valid
        
    do{
        do{  //Input Where To Fire At
        cout<<"Fire at: A"; //Fire at A#
            cin>>fire;
            if (fire<1||fire>10){
                cout<<"Invalid! Input Number 1-10."<<endl; //Output If Invalid
            }
        }while (fire<1||fire>10);  //Input Validation
        tries++;  //Add 1 to tries Count
        
        //Hit or Miss
        if (fire==cShip1){  //Did Ship 1 Get Hit
            cout<<"HIT!";  //Output If Ship 1 is hit
            cS1=false;  //Set cS1 to false (sunk)
        }else if (fire==cShip2){  //Did Ship 2 Get Hit
            cout<<"HIT!";  //Output If Ship 2 is hit
            cS2=false;  //Set cS2 to false (sunk)
        }else cout<<"MISS!";  //Output If No Ships Were Hit
        cout<<endl<<endl;  //Skip a Line
        
        //Opponent Hit or Miss
        if ((tries<=10)&&(cS1==true||cS2==true)&&(s1==true||s2==true)){  //Checks If Game is Still Going
            cFire=rand()%10+1;  //Random Number Chosen for Opponent
            if (cFire==ship1){  //Did Ship 1 Get Hit
                cout<<'A'<<cFire<<" SHIP 1 HAS BEEN HIT!";  //Output If Ship 1 is hit
                s1=false;  //Set s1 to false (sunk)
            }else if (cFire==ship2){  //Did Ship 2 Get Hit
                cout<<'A'<<cFire<<" SHIP 2 HAS BEEN HIT!";  //Output If Ship 2 is hit
                s2=false;  //Set s2 to false (sunk)
            }else cout<<'A'<<cFire<<" OPONENT MISSED!";  //Output If No Ships Were Hit
            cout<<endl<<endl;  //Skip a Line
        }
    }while ((cS1==true||cS2==true)&&(s1==true||s2==true));  //Keep looping until win or lose
    
    if (cS1==false&&cS2==false){  //If All Opponent Ships Are Sunk Output "You Win"
        cout<<"You Win";
    }else cout<<"You Lose";  //If Ships remain Output "You lose"
    
    
    //Exit stage right!
    return 0;
}
