/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on February 3rd, 2020, 11:00 PM
 * Purpose:  1-Line Battleship
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>  //Random Function
#include <ctime>  //Time Library
#include <fstream>  //File Library
#include <iomanip>  //Formating Library
#include <string>  //String Library
#include <cmath>  //Math Library
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variable Data Types and Constants
    unsigned short   fire,  //Location To Fire At
                    cFire,  //Location Opponent Fires At
                    ship1,  //Ship 1 Location
                    ship2,  //Ship 2 Location
                    cShip1, //Opponent Ship 1
                    cShip2; //Opponent Ship 2
    string name;  
    char  tries='0';  //Number of Attempts
    bool  s1=true, //Ship 1 floating or sunk
          s2=true, //Ship 2 floating or sunk
         cS1=true, //Opponent Ship 1 floating or sunk
         cS2=true, //Opponent Ship 2 floating or sunk
         a1=true, a2=true, a3=true, a4=true,  a5=true,  //All Possible Battleship Locations
         a6=true, a7=true, a8=true, a9=true, a10=true,  //True Means Location Has Not Been Fired At
        cA1=true,cA2=true,cA3=true,cA4=true, cA5=true,  //All Possible Opponent Battleship Locations
        cA6=true,cA7=true,cA8=true,cA9=true,cA10=true;  //True Means Location Has Not Been Fired At
    
    //Initialize Variables
    cShip1=rand()%10+1;  //Generate Random Location for Opponents Ship 1
    do{  //Do
        cShip2=rand()%10+1;  //Generate Random Location for Opponents Ship 2
    }while (cShip2==cShip1);  //While Both Ships Are in Same Location

    cout<<"1-Line BATTLESHIP"<<endl;  //Output Name of Game
    cout<<"First name: ";  //Input Name
    getline (cin,name);
 
    //Input Both Ships Location
    bool invalid=true;
    while (invalid==true){   //While Inputs Are Invalid
        invalid=false;
        cout<<"Place Ship 1 at A[1-10]: A";
        cin>>ship1;  //Input Ship 1 Location [1-10]
        cout<<"Place Ship 2 at A[1-10]: A";
        cin>>ship2;  //Input Ship 2 Location [1-10]
        if ((ship1<1||ship1>10)||(ship2<1||ship2>10)||(ship1==ship2)){  //If Input Invalid
            cout<<"Invalid! Input different numbers [1-10] for each ship."<<endl;  //Output Message
            invalid=true;
        }
    }
    
    //Countdown To Begin Battle
    for(int i=3;i>=1;i--){  //3 2 1 ATTACK!
        cout<<i<<endl;
    }
    cout<<"ATTACK!"<<endl;
    
    do{  //Do
        bool valid;
        do{  //Do
            valid=true;
            cout<<"Fire missel at: A";
            cin>>fire;  //Input Where to Fire at [1-10]

            if ((fire<1||fire>10)||  //If Invalid, Number Must Be 1-10
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
                
                cout<<"Invalid! Input different number."<<endl; //Output Message
                valid=false;
            
            }else{  //Else Record Previous Inputs
                (fire==1)?a1=false:  //Set Location To False After Being Fired At
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
          
       }while (valid==false);  //While Input Is Invalid
        tries++;  //Add 1 to Tries Count

        //Hit or Miss
        if (fire==cShip1){  //If Ship 1 Gets Hit
            cout<<"HIT!";  //Output Message
            cS1=false;  //Set cS1 to false (sunk)
        }else if (fire==cShip2){  //If Ship 2 Gets Hit
            cout<<"HIT!";  //Output Message
            cS2=false;  //Set cS2 to false (sunk)
        }else cout<<"MISS!";  //Else Output Message
        cout<<endl<<endl;  //Skip a Line
        
        //Opponent Fires
        if ((cS1==true||cS2==true)&&
             (s1==true||s2==true)){  //If Game is Still Going
            bool cRetry,
                 cValid;
            do{  //Do
                cRetry=false;
                do{  //Do
                    cValid=true;
                    cFire=rand()%10+1;  //Random Number Chosen for Opponent
                    if ((cFire==1&&cA1==false)||  //If Invalid
                         (cFire==2&&cA2==false)||
                         (cFire==3&&cA3==false)||
                         (cFire==4&&cA4==false)||
                         (cFire==5&&cA5==false)||
                         (cFire==6&&cA6==false)||
                         (cFire==7&&cA7==false)||
                         (cFire==8&&cA8==false)||
                         (cFire==9&&cA9==false)||
                         (cFire==10&&cA10==false)){ 
                         cValid=false;  //If Same Number Is Generated More Than Once It's Invalid
                    }
                    if (cValid==true){  //If Valid, Record Location Opponent Fired At
                        switch(cFire){
                            case 1:cA1=false;break;  //Set Location To False After Being Fired At
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
                }while(cValid==false);  //While Invalid
                
                //Opponents Fire Hit or Miss
                if (cFire==ship1&&s1==true){  //If Ship 1 Got Hit
                    cout<<"Opponent: A"<<cFire<<endl
                        <<"SHIP 1 HAS BEEN HIT!";  //Output Message
                    s1=false;  //Set s1 to false (sunk)
                }else if (cFire==ship2&&s2==true){  //Else If Ship 2 Got Hit
                    cout<<"Opponent: A"<<cFire<<endl
                        <<"SHIP 2 HAS BEEN HIT!";  //Output Message
                    s2=false;  //Set s2 to false (sunk)
                }else if (cFire!=ship1&&cFire!=ship2){  //Else If No Ship Was Hit
                    cout<<"Opponent: A"<<cFire<<endl
                        <<"OPPONENT MISSED!";  //Output Message
                }else cRetry=true;
            }while (cRetry==true);  //While Invalid
            cout<<endl<<endl<<endl;  //Skip 2 Lines
        }
    }while ((cS1==true||cS2==true)&&(s1==true||s2==true));  //While Game Is Still Going
    
    //Output Results
    if (cS1==false&&cS2==false){  //If All Opponent Ships Are Sunk
        cout<<":D You Win!"<<endl;  //Output Message And Score
        cout<<"Guesses: "<<tries-48<<endl;
        float score=100.0f;
        score-=pow((tries-48),2);
        cout<<"Score: "<<setprecision(1)<<fixed<<score;
        ofstream file;
        file.open("score_board.txt", ios_base::app);  //Open txt File
        file<<setw(40)<<setfill('.')<<left<<name<<setprecision(1)<<fixed<<score<<endl;  //Write Name and Score Into txt File
        file.close();  //Close txt File
    }else cout<<"You Lose :(";  //Else Output Message
    
    //Exit stage right!
    return 0;
}