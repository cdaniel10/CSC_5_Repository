/* 
 * File:   
 * Author: Christian Daniel
 * Created on: February 7th, 2021, 3:00PM
 * Purpose:  Tic-Tac-Toe
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const int COL=3;  //Number of Columns

//Function Prototypes
void displayBoard(char[][COL],int);
int checkWLT(char[][COL]);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const int SZE=9;  //Array Size
    char gmBoard[SZE][COL]={'*','*','*',
                            '*','*','*',
                            '*','*','*'};  //Initialized Tic-Tac-Toe Board
    int row, clm;  //Row & Column
    
    //Display Board
    displayBoard(gmBoard,SZE);  //Display Board
    
    //Initialize Variables
        do{
            cout<<"Player 1 select location:\n";  //Get Player 1 Input
            cin>>row>>clm;
            gmBoard[row-1][clm-1]='X';  //Place 'X' In Chosen Location
    
            if (checkWLT(gmBoard)==1){  //Check If Player 1 Won
                cout<<"Player 1 has won";
            }else if (checkWLT(gmBoard)==-1){  //Check Game Tie
                cout<<"Tie";
            }else displayBoard(gmBoard,SZE);  //Display Board
            
            if (checkWLT(gmBoard)==0){  //Checks If Game Isn't Over
                cout<<"Player 2 select location:\n";  //Get Player 2 Input
                cin>>row>>clm;
                gmBoard[row-1][clm-1]='O';  //Place 'O' In Chosen Location
            
                if (checkWLT(gmBoard)==2){  //Check If Player 2 Won
                    cout<<"Player 2 has won";
                }else if (checkWLT(gmBoard)==-1){  //Check Game Tie
                    cout<<"Tie";
                }else displayBoard(gmBoard,SZE);  //Display Board
            }
        }while (checkWLT(gmBoard)==0);  //Loop While Game Isn't Over

    //Exit stage right!
    return 0;
}

void displayBoard(char gmBoard[][COL],int SZE){
    for(int i=0; i<SZE/COL; i++){
        for (int j=0; j<SZE/COL; j++){
            cout<<gmBoard[i][j];
            if (j<COL-1){cout<<'|';
            }else cout<<'\n';
        }
        if (i<COL-1) cout<<"-|-|-\n";
    }
}

int checkWLT(char gmBoard[][COL]){
    //return  1 If Player 1 Wins
    //return  2 If Player 2 Wins
    //return  0 If Game Not Over
    //return -1 If Tie
    
    //Diagonal Wins
    if       ((gmBoard[0][0]=='X')&&(gmBoard[1][1]=='X')&&(gmBoard[2][2]=='X')){
        return 1;
    }else if ((gmBoard[0][2]=='X')&&(gmBoard[1][1]=='X')&&(gmBoard[2][0]=='X')){
        return 1;
    }else if ((gmBoard[0][0]=='O')&&(gmBoard[1][1]=='O')&&(gmBoard[2][2]=='O')){
        return 2;
    }else if ((gmBoard[0][2]=='O')&&(gmBoard[1][1]=='O')&&(gmBoard[2][0]=='O')){
        return 2;
    
    //Vertical Wins
    }else if ((gmBoard[0][0]=='X')&&(gmBoard[1][0]=='X')&&(gmBoard[2][0]=='X')){
        return 1;
    }else if ((gmBoard[0][1]=='X')&&(gmBoard[1][1]=='X')&&(gmBoard[2][1]=='X')){
        return 1;
    }else if ((gmBoard[0][2]=='X')&&(gmBoard[1][2]=='X')&&(gmBoard[2][2]=='X')){
        return 1;
    }else if ((gmBoard[0][0]=='O')&&(gmBoard[1][0]=='O')&&(gmBoard[2][0]=='O')){
        return 2;
    }else if ((gmBoard[0][1]=='O')&&(gmBoard[1][1]=='O')&&(gmBoard[2][1]=='O')){
        return 2;
    }else if ((gmBoard[0][2]=='O')&&(gmBoard[1][2]=='O')&&(gmBoard[2][2]=='O')){
        return 2;
    
    //Horizontal Wins
    }else if ((gmBoard[0][0]=='X')&&(gmBoard[0][1]=='X')&&(gmBoard[0][2]=='X')){
        return 1;
    }else if ((gmBoard[1][0]=='X')&&(gmBoard[1][1]=='X')&&(gmBoard[1][2]=='X')){
        return 1;
    }else if ((gmBoard[2][0]=='X')&&(gmBoard[2][1]=='X')&&(gmBoard[2][2]=='X')){
        return 1;
    }else if ((gmBoard[0][0]=='O')&&(gmBoard[0][1]=='O')&&(gmBoard[0][2]=='O')){
        return 2;
    }else if ((gmBoard[1][0]=='O')&&(gmBoard[1][1]=='O')&&(gmBoard[1][2]=='O')){
        return 2;
    }else if ((gmBoard[2][0]=='O')&&(gmBoard[2][1]=='O')&&(gmBoard[2][2]=='O')){
        return 2;
    }else{
    
        //Checks If Game Is Still Going
        int k=0;
        for (int i=0; i<COL; i++){
            for(int j=0; j<COL; j++){
                if (gmBoard[i][j]=='*'){  //Looks For Open Spots In Board
                    k++;
                }
            }
        }
        if (k>0){  //If Game Isn't Over return 0
            return 0;
        }else if (k==0) return -1;  //If Game Tie return -1
    }
}