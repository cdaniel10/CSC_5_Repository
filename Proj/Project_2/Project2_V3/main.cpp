/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on February 9th, 2021, 5:00 PM
 * Purpose:  Battleship
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>  //Random Function
#include <ctime>  //Time Library
#include <fstream>  //File I/O
#include <iomanip>  //Formatting Library
#include <string>  //String Library
#include <cmath>  //Math Library
#include <vector>  //Vector Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays
const int COL=5;  //Number of Columns

//Function Prototypes
void displayBoard(char[][COL],int=25);  //Display Game Board
void generateShips(char[][COL]);  //Randomly Generate Battleship Locations
void getUserInp(char[][COL],char[][COL]);  //Get User Input
void opponent(char[][COL]);  //Opponent Attacks
bool game(char[][COL],char[][COL],int&);  //Checks If Game Over And Returns Winner
void reset(char[][COL],int);  //Resets Game Board
string title();  //Name Of Game
float score(char[][COL],int,string);  //Get Score
void score(char[][COL],string,float);  //Add to Score Board
void lose(char[][COL],vector<char>&);  //Copy Opponent Board
void loseP(vector<char>&,int);  //Output Mini Opponent Board
void boarder(char []);  //Output Boarder

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare And Initialize Variables
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
    vector<char> mBoard(SZE);
    char brder [30];
    bool gameOvr;
    int winner;
    string name;
    int choice;
    
    //Generate Ships
    generateShips(oBoard);  //Generate Opponent Ships Randomly
    generateShips(uBoard);  //Generate Users Ships Randomly
    
    //Output Title
    boarder(brder);
    cout<<setw(20)<<title()<<endl;
    boarder(brder);
    
    //Input Name
    cout<<"Enter Name: ";
    getline (cin,name);
    
    //Choose Battleship Locations
    do{
        cout<<"Your Battleship Locations"<<endl;
        displayBoard(uBoard,SZE);
        cout<<"Enter 1 To Change Battleship Locations.\n";
        cout<<"Enter 2 To Quit.\n";
        cout<<"Enter Anything Else To Proceed\n";
        cin>>choice;  //Input Choice 
        switch (choice){
            case 1: reset(uBoard,SZE);  //Reset Board And Generate New Ships
                    generateShips(uBoard);break;
            case 2: exit(0);  //Exit Program
        }
    }while (choice==1);  //While Choice Is To Generate New Ship Locations
    
    //Game Begins
    cout<<"\n\nGet Ready For Battle "<<name<<"!\n\n";
    do{
        getUserInp(oBoard,dBoard);  //Get USer Input
        gameOvr=game(uBoard,oBoard,winner);
        if(!gameOvr){  //Check If Game Is Over
            cout<<"Opponents Board\n";
            displayBoard(dBoard);  //Output Opponents Board
            opponent(uBoard);  //Opponents Turn
            cout<<"Your Board\n";
            displayBoard(uBoard);  //Display Users Board
            gameOvr=game(uBoard,oBoard,winner);  //Check if Game Is Over
        }
    }while(!gameOvr);  //Loop While Game Is Not Over
    
    //Game Over
    while(gameOvr){  //While Game Is Over
        game(uBoard,oBoard,winner);  //Check Who Won
        (winner==1)?cout<<"\n:D You Win!\n":  //Output If Win
                    cout<<"\nYou Lose :(\n\n";  //Output If Lose
        if(winner==1){  //If User Wins
            float scr=score(oBoard,SZE,name);  //Output Score
            score(oBoard,name,scr);  //Add Score To Scoreboard
        }
        if(winner==2){  //If Opponent Wins
            cout<<"Opponents Ships\n";
            lose(oBoard,mBoard);  //Copy Opponent Board
            loseP(mBoard,SZE);  //Output Mini Opponent Board
        }
        gameOvr=false;  //Exit Loop
    }
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
    
    //Get User Input To Launch Missel
    do{
        cout<<"Launch Missel At Opponent [Row][Column]"<<endl;
            cin>>row>>column;  //Input Row and Column
            cout<<endl;
            row-=1;
            column-=1;
    }while(oBoard[row][column]=='X'||
           oBoard[row][column]=='H'||
           row<0||row>4||column<0||column>4);  //Input Validation
    //Hit or Miss
    if (oBoard[row][column]=='O'){  //If User Hits Opponents Ship
        cout<<"Fired At: ["<<row+1<<"]["<<column+1<<"]\n";
        cout<<"YOU SUNK AN OPPONENTS SHIP!\n";
        oBoard[row][column]='H';
        dBoard[row][column]='H';
    }else{ //Else User Missed
        cout<<"Fired At: ["<<row+1<<"]["<<column+1<<"]\n";
        cout<<"Oh No! You Missed!\n";
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
        cout<<"Opponent: ["<<row+1<<"]["<<column+1<<"]"<<endl;
        cout<<"Opponent Has Hit Your Ship!"<<endl;
        uBoard[row][column]='H';
    }else{  //Else Opponent Missed
        cout<<"Opponent: ["<<row+1<<"]["<<column+1<<"]"<<endl;
        cout<<"Opponent Missed!"<<endl;
        uBoard[row][column]='X';
    }
}

void displayBoard(char board[][COL],int SZE){
    //Displays Any Board Passed In
    for(int i=0; i<SZE/COL; i++){
        for (int j=0; j<COL; j++){
            cout<<board[i][j];
            if (j<COL-1){cout<<'|';
            }else cout<<'\n';
        }
    if (i<COL-1) cout<<"-+-+-+-+-\n";
    }cout<<endl;
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

void reset(char board[][COL],int SZE){
    //Clear Any Board Passed In
    for(int i=0; i<SZE/COL; i++){
        for (int j=0; j<COL; j++){
            board[i][j]='*';
        }
    }
}

void lose(char oBoard[][COL],vector<char>&mBoard){
    for(int i=0,k=0;i<COL;i++){  //Copy Opponent Board To Vector
        for(int j=0;j<COL;j++){
            mBoard[k]=oBoard[i][j];
            k++;
        }
    }
}

void loseP(vector<char>&mBoard,int SZE){
    for(int i=0;i<SZE;i++){  //Output Mini Opponent Board
        cout<<mBoard[i];
        if (i%5==4&&i!=0)cout<<endl;
        else cout<<'|';
    }
}

string title(){
    //Declare
    string title;
    ifstream inFile ("title.txt"); //Open File
    inFile>>title;  //Read Name Of Game
    inFile.close();  //Close File
    return title;  //Return The Name
}

float score(char board[][COL],int SZE,string name){  //Calculate Score
    int count=0;  //Misses Count
    for(int i=0; i<SZE/COL; i++){
        for (int j=0; j<COL; j++){
            if (board[i][j]=='X'){  //Count All Misses
                count++;
            }
        }
    }
    float score=100.0f;  //Top Score (0 Misses)
    score-=pow(count,1.53f);  //Misses Exponentially Deduct From Score
    cout<<name<<" Got A Score Of "  //Output Score
            <<setprecision(1)<<fixed<<showpoint<<score<<endl;
    cout<<"Number Of Misses: "<<count<<endl;  //Output Number Of Misses
    return score;  //Return The Score
}

void score(char board[][COL],string name,float score){  //Add To Scoreboard
    //Declare
    ofstream outFile;
    outFile.open("soreboard.txt", ios_base::app);  //Open File
    outFile<<setw(40)<<setfill('.')<<left<<name    //Add Name And Score To Scoreboard
            <<setprecision(1)<<fixed<<showpoint<<score<<endl;
    outFile.close();  //Close File
}

void boarder(char brder[]){
    //Output Boarder
    for(int i=0;i<30;i++){
        brder[i]='*';
        cout<<brder[i];
    }cout<<endl;
}