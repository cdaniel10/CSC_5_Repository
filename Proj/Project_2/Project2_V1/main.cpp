/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on February 8th, 2021, 7:00 PM
 * Purpose:  Battleship
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

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays
const int COL=5;  //Number of Columns

//Function Prototypes
void displayBoard(char[][COL],int=25);
void generateShips(char[][COL],int);
void getUserInp(char[][COL],char[][COL]);
void opponent(char[][COL],int);
bool game(char[][COL],char[][COL],int&);
void reset(char[][COL],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SZE=25;  //Size of Array
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
    bool gameOvr;
    int winner;
    string name;
    
    //Initialize Variables
    generateShips(oBoard,SZE);  //Generate Opponent Ships Randomly
    generateShips(uBoard,SZE);  //Generate Users Ships Randomly
    int choice;
    cout<<"BATTLESHIP"<<endl<<endl;
    cout<<"Enter Name: ";  //Input Name
    getline (cin,name);
    
    //Choose Battleship Locations
    do{
        cout<<"Your Battleship Locations"<<endl;
        displayBoard(uBoard,SZE);
        cout<<"Enter 1 To Change Battleship Locations.\n";
        cout<<"Enter Anything Else To Proceed\n";
        cin>>choice;
        switch (choice){
            case 1: reset(uBoard,SZE);
                    generateShips(uBoard,SZE);break;
        }
    }while (choice==1);  //While Choice Is To Generate New Ship Locations
    
    //Game Begins
    cout<<"\n\nGet Ready For Battle "<<name<<"!\n\n";
    do{
        getUserInp(oBoard,dBoard);
        gameOvr=game(uBoard,oBoard,winner);
        if(!gameOvr){
            cout<<"Opponents Board\n";
            displayBoard(dBoard);
            opponent(uBoard,SZE);
            cout<<"Your Board\n";
            displayBoard(uBoard);
            gameOvr=game(uBoard,oBoard,winner);
        }
    }while(!gameOvr);
    
    //Game Over
    while(gameOvr){
        game(uBoard,oBoard,winner);
        (winner==1)?cout<<"You Win!":
                    cout<<"You Lose";
        gameOvr=false;
    }
 
    return 0;
}

bool game(char uBoard[][COL],char oBoard[][COL],int &winner){
    //Initialize
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
    if (opp==false&&user==true)winner=2;  //If Opponent Sunk All User Ships, Opp Wins
    if (user==true&&opp==true) return false;  //If Both Players Are Still In Game, Game Is Not Over
    else return true;  //Else Game Over
}

void getUserInp(char oBoard[][COL],char dBoard[][COL]){
    //Declare
    int row, 
     column;
    
    //Get User Input To Launch Missel
    do{
        cout<<"Launch Missel At Opponent [Row][Column}"<<endl;
            cin>>row>>column;
            cout<<endl;  //
            row-=1;
            column-=1;
    }while(oBoard[row][column]=='X'||
           oBoard[row][column]=='H'||
           row<0||row>4||column<0||column>4);  //Input Validation
    //Hit or Miss
    if (oBoard[row][column]=='O'){  //If User Hits Opponents Ship
        cout<<"YOU SUNK AN OPPONENTS SHIP!\n\n";
        oBoard[row][column]='H';
        dBoard[row][column]='H';
    }else{ //Else User Missed
        cout<<"Oh no! You missed!\n\n";
        oBoard[row][column]='X';
        dBoard[row][column]='X';
    }
}

void opponent(char uBoard[][COL],int SZE){
    //Declare
    int row, 
     column;
    //Generate Opponents Missel Launch Location
    do{
        row=rand()%5;
        column=rand()%5;
    }while(uBoard[row][column]=='X');  //Validation
    //Hit or Miss
    if (uBoard[row][column]=='O'){  //If Opponent Hits users Ship
        cout<<"Opponent Has Hit Your Ship!"<<endl;
        uBoard[row][column]='H';
    }else{  //Else Opponent Missed
        cout<<"Opponent Missed!"<<endl;
        uBoard[row][column]='X';
    }
}

void displayBoard(char gmBoard[][COL],int SZE){
    //Displays Any Board Passed In
    for(int i=0; i<SZE/COL; i++){
        for (int j=0; j<SZE/COL; j++){
            cout<<gmBoard[i][j];
            if (j<COL-1){cout<<'|';
            }else cout<<'\n';
        }
        if (i<COL-1) cout<<"---------\n";
    }cout<<endl;
}

void generateShips(char board[][COL],int SZE){
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

void reset(char board[][COL],int SZE){
    //Clear Any Board Passed In
    for(int i=0; i<SZE/COL; i++){
        for (int j=0; j<SZE/COL; j++){
            board[i][j]='*';
        }
    }
}