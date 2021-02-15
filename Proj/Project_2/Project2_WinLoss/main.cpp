/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on February 13th, 2021, 10:00 PM
 * Purpose:  Battleship Win Loss Count
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>  //Random Function
#include <ctime>  //Time Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays
const int COL=5;  //Number of Columns

//Function Prototypes
void generateShips(char[][COL]);  //Randomly Generate Battleship Locations
void getUserInp(char[][COL],char[][COL]);  //Get User Input
void opponent(char[][COL]);  //Opponent Attacks
bool game(char[][COL],char[][COL],int&);  //Checks If Game Over And Returns Winner

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare And Initialize Variables
    const int SZE=25;  //Size of Array
    bool gameOvr;
    int winner;
    
    //Test
    int games=100000;  //Number of Games Played
    int win=0,  //Number of Wins
       lose=0;  //Number of Losses
    
    do{
         //Declare And Initialize Boards
        char oBoard[SZE][COL]={'*','*','*','*','*',
                               '*','*','*','*','*',
                               '*','*','*','*','*',
                               '*','*','*','*','*',
                               '*','*','*','*','*'};  //Initialize Opponents Hidden Board
        char uBoard[SZE][COL]={'*','*','*','*','*',
                               '*','*','*','*','*',
                               '*','*','*','*','*',
                               '*','*','*','*','*',
                               '*','*','*','*','*'};  //Initialize Users Board
        char dBoard[SZE][COL]={'*','*','*','*','*',
                               '*','*','*','*','*',
                               '*','*','*','*','*',
                               '*','*','*','*','*',
                               '*','*','*','*','*'};  //Initialize Opponents Displayed Board
        //Generate Ships
        generateShips(oBoard);  //Generate Opponent Ships Randomly
        generateShips(uBoard);  //Generate Users Ships Randomly

        do{
            getUserInp(oBoard,dBoard);  //Get USer Input
            gameOvr=game(uBoard,oBoard,winner);
            if(!gameOvr){  //Check If Game Is Over
                opponent(uBoard);  //Opponents Turn
                gameOvr=game(uBoard,oBoard,winner);  //Check if Game Is Over
            }
        }while(!gameOvr);  //Loop While Game Is Not Over

        //Game Over
        while(gameOvr){  //While Game Is Over
            game(uBoard,oBoard,winner);  //Check Who Won
            if(winner==1){  //If User Wins
                win++;
            }
            if(winner==2){  //If Opponent Wins
                lose++;
            }
            gameOvr=false;  //Exit Loop
        }
    }while((lose+win)<games);
    
    //Output Results
    cout<<"Number of Games Played: "<<games<<endl;
    cout<<"Number of Wins:   "<<win<<endl;  //Wins Should Be Slightly Greater Than Losses
    cout<<"Number of Losses: "<<lose<<endl; //Due to User Having The Advantage of Going First
    
    return 0;
}

bool game(char uBoard[][COL],char oBoard[][COL],int &winner){
    //Declare/Initialize
    bool user=false,
          opp=false;
    
    //Search Boards
    //Loop Through Every Index And Look For Remaining User Ships
    for(int i=0;i<COL;i++){
        for(int j=0;j<COL;j++){
            if (uBoard[i][j]=='O'){  //If User Ships Are Left
                opp=true;
            }
        }
    }
    //Loop Through Every Index And Look For Remaining Opponent Ships
    for(int i=0;i<COL;i++){
        for(int j=0;j<COL;j++){
            if (oBoard[i][j]=='O'){  //If Opponent Ships Are Left
                user=true;
            }
        }
    }
    //Results
    if (user==false&&opp==true)winner=1;  //If User Sunk All Opponent Ships, User Wins
    else if (opp==false&&user==true)winner=2;  //If Opponent Sunk All User Ships, Opp Wins
    if (user==true&&opp==true) return false;  //If Both Players Are Still In Game, Game Is Not Over
    else return true;  //Else Game Over
}

void getUserInp(char oBoard[][COL],char dBoard[][COL]){
    //Declare
    int row, 
     column;
    //Generate Opponents Missel Launch Location
    do{
        row=rand()%5;
        column=rand()%5;
    }while(oBoard[row][column]=='X'||oBoard[row][column]=='H');  //Validation
    //Hit or Miss
    if (oBoard[row][column]=='O'){  //If User Hits Opponents Ship
        oBoard[row][column]='H';
        dBoard[row][column]='H';
    }else{ //Else User Missed
        oBoard[row][column]='X';
        dBoard[row][column]='X';
    }
}

void opponent(char uBoard[][COL]){
    //Declare
    int row, 
     column;
    //Generate Opponents Missel Launch Location
    do{
        row=rand()%5;
        column=rand()%5;
    }while(uBoard[row][column]=='X'||uBoard[row][column]=='H');  //Validation
    //Hit or Miss
    if (uBoard[row][column]=='O'){  //If Opponent Hits users Ship
        uBoard[row][column]='H';
    }else{  //Else Opponent Missed
        uBoard[row][column]='X';
    }
}

void generateShips(char board[][COL]){
    //Declare/Initialize
    const int numShps=5;
    int row,
     column;
    //Generate 5 Random Ship Locations
    for(int i=0; i<numShps; i++){
        do{
            row=rand()%5;  //Generate Random Row
            column=rand()%5;  //Generate Random Column
        }while (board[row][column]=='O');  //While Ship Already In Location
        //Set Ship In Generated Location
        board[row][column]='O';
    }
}
