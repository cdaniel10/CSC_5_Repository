/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on February 3rd, 2020, 11:00 PM
 * Purpose:  1-Line Battleship
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
                    cShip1, //Opponent Ship 1
                    cShip2; //Opponent Ship 2
    bool  s1=true, //Ship 1 floating or sunk
          s2=true, //Ship 2 floating or sunk
         cS1=true, //Opponent Ship 1 floating or sunk
         cS2=true, //Opponent Ship 2 floating or sunk
        a1=true,a2=true,a3=true,a4=true,a5=true,
        a6=true,a7=true,a8=true,a9=true,a10=true,
        cA1=true,cA2=true,cA3=true,cA4=true,cA5=true,
        cA6=true,cA7=true,cA8=true,cA9=true,cA10=true;
    //Initialize Variables
    cShip1=rand()%10+1;
    do{
        cShip2=rand()%10+1;
    }while (cShip2==cShip1);  //Makes Sure Both Ships Aren't in Same Location

    cout<<cShip1<<'\t'<<cShip2<<endl;
    
    do{  //Input Ships Location
        cout<<"Place Ship 1 at A[1-10]: A";
        cin>>ship1;
        cout<<"Place Ship 2 at A[1-10]: A";
        cin>>ship2;
        cout<<endl<<endl;
        if ((ship1<1||ship1>10)||(ship2<1||ship2>10)||(ship1==ship2)){  //Input Validation
            cout<<"Invalid! Input different numbers [1-10] for each ship."<<endl;
        }
    }while ((ship1<1||ship1>10)||(ship2<1||ship2>10)||(ship1==ship2));  //Loop Until Inputs Are Valid
        
    do{
        bool valid;
        do{  //Input Where To Fire At
            valid=true;
            cout<<"Fire missel at: A"; //Fire at A#
            cin>>fire;

            if ((fire<1||fire>10)||  //Number Must Be 1-10
                (fire==1&&a1==false)||  //Can't Fire At Same Spot Twice
                (fire==2&&a2==false)||
                (fire==3&&a3==false)||
                (fire==4&&a4==false)||
                (fire==5&&a5==false)||
                (fire==6&&a6==false)||
                (fire==7&&a7==false)||
                (fire==8&&a8==false)||
                (fire==9&&a9==false)||
                (fire==10&&a10==false)){
                
                cout<<"Invalid! Input different number."<<endl; //Output If Invalid
                valid=false;
            
            }else{//Record Previous Inputs
                (fire==1)?a1=false:
                (fire==2)?a2=false:
                (fire==3)?a3=false:
                (fire==4)?a4=false:
                (fire==5)?a5=false:
                (fire==6)?a6=false:
                (fire==7)?a7=false:
                (fire==8)?a8=false:
                (fire==9)?a9=false:
                (fire==10)?a10=false:1;
            }
          
       }while (valid==false);  //Input Validation
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
        if ((tries<=10)&&(cS1==true||cS2==true)&&
                          (s1==true||s2==true)){  //Checks If Game is Still Going
            bool cRetry,
                 cValid;
            do{
                cRetry=false;
                do{
                    cValid=true;
                    cFire=rand()%10+1;  //Random Number Chosen for Opponent
                    if ((cFire==1&&cA1==false)||  //Can't Fire At Same Spot Twice
                         (cFire==2&&cA2==false)||
                         (cFire==3&&cA3==false)||
                         (cFire==4&&cA4==false)||
                         (cFire==5&&cA5==false)||
                         (cFire==6&&cA6==false)||
                         (cFire==7&&cA7==false)||
                         (cFire==8&&cA8==false)||
                         (cFire==9&&cA9==false)||
                         (cFire==10&&cA10==false)){ 
                         cValid=false;
                    }
                    if (cValid==true){
                        switch(cFire){  //Record Opponents Fires
                            case 1:cA1=false;break;
                            case 2:cA2=false;break;
                            case 3:cA3=false;break;
                            case 4:cA4=false;break;
                            case 5:cA5=false;break;
                            case 6:cA6=false;break;
                            case 7:cA7=false;break;
                            case 8:cA8=false;break;
                            case 9:cA9=false;break;
                            case 10:cA10=false;break;
                        }  
                    }
                }while(cValid==false);
                
                if (cFire==ship1&&s1==true){  //Did Ship 1 Get Hit
                    cout<<"Opponent: A"<<cFire<<endl
                        <<"SHIP 1 HAS BEEN HIT!";  //Output If Ship 1 is hit
                    s1=false;  //Set s1 to false (sunk)
                }else if (cFire==ship2&&s2==true){  //Did Ship 2 Get Hit
                    cout<<"Opponent: A"<<cFire<<endl
                        <<"SHIP 2 HAS BEEN HIT!";  //Output If Ship 2 is hit
                    s2=false;  //Set s2 to false (sunk)
                }else if (cFire!=ship1&&cFire!=ship2){
                    cout<<"Opponent: A"<<cFire<<endl
                        <<"OPPONENT MISSED!";  //Output If No Ships Were Hit
                }else cRetry=true;  //Generate New Number If Ship Has Previously Been Hit
            }while (cRetry==true);
            cout<<endl<<endl<<endl;  //Skip 2 Lines
        }
        
    }while ((cS1==true||cS2==true)&&(s1==true||s2==true));  //Keep looping until win or lose
    
    if (cS1==false&&cS2==false){  //If All Opponent Ships Are Sunk Output "You Win"
        cout<<":D You Win!"<<endl;
        cout<<"Guesses: "<<tries;
    }else cout<<"You Lose :(";  //If Ships remain Output "You lose"
    
    //Exit stage right!
    return 0;
}
