/* 
 * File:   main.cpp
 * Author: Christian Daniel
 * Created on January 18, 2021, 11:59 PM
 * Purpose: Menu
 */
//System Level Libraries
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    //Variable Declarations
    char choice;

    //Display Menu
    cout<<"Menu"<<endl;
    cout<<"Type 1 for Gaddis Sort Names Problem"<<endl;
    cout<<"Type 2 for Gaddis Books Problem"<<endl;
    cout<<"Type 3 for Gaddis Bank Charges Problem"<<endl;
    cout<<"Type 4 for Gaddis Race Problem"<<endl;
    cout<<"Type 5 for Gaddis ISP Problem"<<endl;
    cout<<"Type 6 for Savitch Rock Paper Scissors Problem"<<endl;
    cout<<"Type 7 for Savitch Roman Conversion Problem"<<endl;
    cout<<"Type 8 for Savitvh Compatible Signs Problem"<<endl;
    
    cin>>choice;
    
    switch(choice){
        case '1':{
            //Declare Variables
            string n1, n2, n3;  //3 Names
    
            cout<<"Sorting Names\nInput 3 names\n";
            cin>>n1>>n2>>n3;

            //All Possible Arrangements Using First Letter of Each Name
            if      (n2[0]<n3[0] && n2[0]>n1[0]){
                        cout<<n1<<'\n'<<n2<<'\n'<<n3;}
            else if (n3[0]<n2[0] && n3[0]>n1[0]){
                        cout<<n1<<'\n'<<n3<<'\n'<<n2;}
            else if (n3[0]<n1[0] && n3[0]>n2[0]){
                        cout<<n2<<'\n'<<n3<<'\n'<<n1;}
            else if (n1[0]<n3[0] && n1[0]>n2[0]){
                        cout<<n2<<'\n'<<n1<<'\n'<<n3;}
            else if (n1[0]<n2[0] && n1[0]>n3[0]){
                        cout<<n3<<'\n'<<n1<<'\n'<<n2;}
            else if (n2[0]<n1[0] && n2[0]>n3[0]){
                        cout<<n3<<'\n'<<n2<<'\n'<<n1;}
            break;}
        case '2':{
            //Declare Variables
            unsigned short numBook, ptsEarn; //Number of Books Purchased & Points Earned

            //Map inputs -> outputs
            cout<<"Book Worm Points\nInput the number of books purchased this month.\n";
            cin>>numBook;

            ptsEarn = (numBook==0)? 0:
                      (numBook==1)? 5:
                      (numBook==2)?15:
                      (numBook==3)?30:60;

            //Display the outputs
            cout<<"Books purchased ="<<setw(3)<<numBook<<endl;
            cout<<"Points earned   ="<<setw(3)<<ptsEarn;
            break;}
        case '3':{
            //Declare Variables
            float   begBlnc, //Beginning Balance
                    numChks, //Number of Checks
                     chkFee, //Check Fee
                     lowFee, //Low Balance Fee
                      nBlnc, //New Balance
                     monFee; //Monthly Fee

            //Map inputs -> outputs
            cout<<"Monthly Bank Fees\nInput Current Bank Balance and Number of Checks\n";
            cin>>begBlnc>>numChks;

            if (numChks>=0){

                chkFee = (numChks<20)?0.10:  //Check Fee in USD
                         (numChks<40)?0.08:
                         (numChks<60)?0.06:0.04;

                lowFee = (begBlnc>=400)?0.00:15.00; //Low Balance Fee in USD

                monFee = 10.00; //Monthly Fee in USD

                nBlnc = begBlnc-(chkFee*numChks)-lowFee-monFee; //Balance minus Fees

                //Display the outputs
                cout<<"Balance     $"<<setw(9)<<setprecision(2)<<fixed<<begBlnc<<endl;
                cout<<"Check Fee   $"<<setw(9)<<setprecision(2)<<fixed<<chkFee*numChks<<endl;
                cout<<"Monthly Fee $"<<setw(9)<<setprecision(2)<<fixed<<monFee<<endl;
                cout<<"Low Balance $"<<setw(9)<<setprecision(2)<<fixed<<lowFee<<endl;
                cout<<"New Balance $"<<setw(9)<<setprecision(2)<<fixed<<nBlnc;

                if (begBlnc<0){
                    cout<<"\nUrgent Message: Your Account is Overdrawn.";
                }
            }
            break;}
        case '4':{
            //Declare Variables
            string         name1, name2, name3,  first,  second,  third;
            unsigned short time1, time2, time3, tFirst, tSecond, tThird;

            //Map inputs -> outputs
            cout<<"Race Ranking Program\n";
            cout<<"Input 3 Runners\n";
            cout<<"Their names, then their times\n";
            cin>>name1>>time1;
            cin>>name2>>time2;
            cin>>name3>>time3;

            //All Possible Arrangements
            if (time2<time3 && time2>time1){
                first  = name1;
                second = name2;
                third  = name3;
                tFirst  = time1;
                tSecond = time2;
                tThird  = time3;
            }else if (time3<time3 && time3>time2){
                first  = name2;
                second = name3;
                third  = name1;
                tFirst  = time2;
                tSecond = time3;
                tThird  = time1;
            }else if (time1<time2 && time1>time3){
                first  = name3;
                second = name1;
                third  = name2;
                tFirst  = time3;
                tSecond = time1;
                tThird  = time2;
            }else if (time3<time2 && time3>time1){
                first  = name1;
                second = name3;
                third  = name2;
                tFirst  = time1;
                tSecond = time3;
                tThird  = time2;
            }else if (time1<time3 && time1>time2){
                first  = name2;
                second = name1;
                third  = name3;
                tFirst  = time2;
                tSecond = time1;
                tThird  = time3;
            }else if (time2<time1 && time2>time3){
                first  = name3;
                second = name2;
                third  = name1;
                tFirst  = time3;
                tSecond = time2;
                tThird  = time1;
            }
            //Display the outputs
            cout<<first <<'\t'<<setw(3)<<tFirst<<endl;
            cout<<second<<'\t'<<setw(3)<<tSecond<<endl;
            cout<<third <<'\t'<<setw(3)<<tThird;
            break;}
        case '5':{
            //Declare Variables
            char pack;
            unsigned short hours;
            float bill;

            //Map inputs -> outputs
            cout<<"ISP Bill\nInput Package and Hours\n";
            cin>>pack>>hours;

            if       (pack=='A'){
                bill = (hours<=10) ? 9.95 : (hours-10)*2.00+9.95;   //$9.95/month plus $2/every additional hour after 10
                cout<<"Bill = $"<<setw(6)<<setprecision(2)<<fixed<<bill;
            }else if (pack=='B'){
                bill = (hours<=20) ? 14.95 : (hours-20)*1.00+14.95; //$14.95/month plus $1/every additional hour after 20
                cout<<"Bill = $"<<setw(6)<<setprecision(2)<<fixed<<bill;
            }else if (pack=='C'){
                bill = 19.95;                                       //$19.95/month
                cout<<"Bill = $"<<setw(6)<<setprecision(2)<<fixed<<bill;
            }
            break;}
        case '6':{
            //Declare Variables
            char p1, p2;  //Player 1 and Player 2

            //Map inputs -> outputs
            cout<<"Rock Paper Scissors Game\nInput Player 1 and Player 2 Choices\n";
            cin>>p1>>p2;

            //Nobody Wins
            if      ((p1=='R' || p1=='r')&&(p2=='R' || p2=='r')){
                cout<<"Nobody wins.";}
            else if ((p1=='P' || p1=='p')&&(p2=='P' || p2=='p')){
                cout<<"Nobody wins.";}
            else if ((p1=='S' || p1=='s')&&(p2=='S' || p2=='s')){
                cout<<"Nobody wins.";}

            //Paper Wins
            else if ((p1=='R' || p1=='r')&&(p2=='P' || p2=='p')){
                cout<<"Paper covers rock.";}
            else if ((p1=='P' || p1=='p')&&(p2=='R' || p2=='r')){
                cout<<"Paper covers rock.";}

            //Rock Wins
            else if ((p1=='R' || p1=='r')&&(p2=='S' || p2=='s')){
                cout<<"Rock breaks scissors.";}
            else if ((p1=='S' || p1=='s')&&(p2=='R' || p2=='r')){
                cout<<"Rock breaks scissors.";}

            //Scissors Win
            else if ((p1=='P' || p1=='p')&&(p2=='S' || p2=='s')){
                cout<<"Scissors cuts paper.";}
            else if ((p1=='S' || p1=='s')&&(p2=='P' || p2=='p')){
                cout<<"Scissors cuts paper.";}
            break;}
        case '7':{
            //Declare Variables
            unsigned short n2Cnvrt;  //Number to Convert

            //Initialize or input i.e. set variable values
            cout<<"Arabic to Roman numeral conversion.\nInput the integer to convert.\n";
            cin>>n2Cnvrt;

            //Map inputs -> outputs
            if (n2Cnvrt>=1000 && n2Cnvrt<=3000){  //Input Must Be Between 1000 and 3000
                cout<<n2Cnvrt<<" is equal to ";

                //Determine 1000s, 100s, 10s, 1s
                unsigned char n1000s, n100s, n10s, n1s;
                n1000s = n2Cnvrt/1000;
                n100s  = n2Cnvrt%1000/100;
                n10s   = n2Cnvrt%100/10;
                n1s    = n2Cnvrt%10;

                //Output the Number of 1000s
                switch (n1000s){
                    case 3:cout<<'M';
                    case 2:cout<<'M';
                    case 1:cout<<'M';}

                //Output the Number of 100s
                cout<<(n100s==9?"CM":
                       n100s==8?"DCCC":
                       n100s==7?"DCC":
                       n100s==6?"DC":
                       n100s==5?"D":
                       n100s==4?"CD":
                       n100s==3?"CCC":
                       n100s==2?"CC":
                       n100s==1?"C":"");

                //Output the Number of 10s
                cout<<(n10s==9?"XC":
                       n10s==8?"LXXX":
                       n10s==7?"LXX":
                       n10s==6?"LX":
                       n10s==5?"L":
                       n10s==4?"XL":
                       n10s==3?"XXX":
                       n10s==2?"XX":
                       n10s==1?"X":"");

                //Output the Number of 1s
                cout<<(n1s==9?"IX":
                       n1s==8?"VIII":
                       n1s==7?"VII":
                       n1s==6?"VI":
                       n1s==5?"V":
                       n1s==4?"IV":
                       n1s==3?"III":
                       n1s==2?"II":
                       n1s==1?"I":"");

            }else cout<<n2Cnvrt<<" is Out of Range!";
            break;}
        case '8':{
            //Declare Variables
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
            break;}
       
    } //End of Switch Case
 return 0;
}