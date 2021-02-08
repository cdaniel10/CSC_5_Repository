/* 
 * File: main.cpp
 * Author: ChrisTian Daniel
 * Created on: February 7th, 2021, 8:30 PM
 * Purpose:  Selection/Bubble Sort
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int selcSrt(int [],int,int,int);
int bublSrt(int [],int,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    const int SIZE=40;
    int start, end, selSrt, bblSrt;
    int arr1 []={
            81,36,37,85,52,70,38,55,31,37,
            27,58,32,40,99,79,92,31,32,64,
            92,35,85,66,27,67,23,11,91,88,
            17,18,71,49,13,82,68,82,23,12
    };
    int arr2 []={
            81,36,37,85,52,70,38,55,31,37,
            27,58,32,40,99,79,92,31,32,64,
            92,35,85,66,27,67,23,11,91,88,
            17,18,71,49,13,82,68,82,23,12
    };

    //Initialize Variables
    cout<<"Enter the starting location to sort:\n";
    cin>>start;
    cout<<"Enter the ending location to sort:\n";
    cin>>end;
    
    //Process or map Inputs to Outputs
    selSrt=selcSrt(arr1,SIZE,start,end);  //Number of Swaps
    bblSrt=bublSrt(arr2,SIZE,start,end);  //Number of Swaps
    
    //Display Outputs
    cout<<"Selection Sort "<<selSrt<<endl;
    cout<<"Bubble Sort "<<bblSrt;
    
    //Exit stage right!
    return 0;
}

int selcSrt(int a[],int n,int start,int end){
    int count=0;  //Swap Count
    for(int i=start;i<end-1;i++){  //Loop for each position in List
        int idxMin=i;
        for(int j=i+1;j<n;j++){  //Loop to swap with first in List
            if(a[idxMin]>a[j]){  //Put the smallest at top of List
                idxMin=j;
            }
        }
        int temp=a[i];
        a[i]=a[idxMin];
        a[idxMin]=temp;
        count++;
    }
    return count;
}
int bublSrt(int a[],int n, int start, int end){
    bool swap;
    int count=0;  //Swap Count
    do{
        swap=false;
        for(int i=start;i<end-1;i++){  //Loop to swap with first in List
            if(a[i]>a[i+1]){       //Put the smallest at top of List
                a[i]=a[i]^a[i+1];  //In place Swap
                a[i+1]=a[i]^a[i+1];  //In place Swap
                a[i]=a[i]^a[i+1];  //In place Swap
                count++;
                swap=true;
            }
        }
    }while(swap);
    return count;
}