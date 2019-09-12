#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

void SetFile(int a , int b, ofstream& output){
    if(b == 0){
        for(int i = 0; i < a - 1; i++)
        output << rand()%100000 << endl;                  // Randomly created a words
        output << rand()%100000;
    }
    if(b == 1){
        int randgap = rand()%100;                        // Randomly created gaps between each sorted word
        int randnum = rand()%100000 + a * randgap;
        for(int i = a-1; i > 0; i--){
            output << randnum << endl;
            randnum = randnum - randgap;                 // Reversely set the numbers
        }
        output << randnum;
    }
    if(b == 2){
        int arraynum = a * 20 / 100;                   // Set a 20% array which are all unique number
        int temparray[arraynum];
        for(int i = 0; i < arraynum; i++){
            temparray[i] = rand()%100000;
            output << temparray[i] << endl;           // Set the Unique array
        }
        for(int j = 0; j < (a - arraynum-1); j++){
             output << temparray[rand()&arraynum - 1] << endl;      // Set the rest, choose from the Unique array
        }
        output << temparray[rand()&arraynum - 1];
    }
    if(b == 3){
        int arraynum = a * 30 / 100;                   // Set target number of random number
        int startnum = rand()%100000;
        int randgap = rand()%10 + 1;                   // Set the incremental gap
            for(int i = 0; i < a-1; i++){
                int trigger = rand()%2;                // If choose to set unsorted number, Set a totally different number 
                if(trigger == 0 && arraynum!= 0){
                    output << rand()%1000 + startnum + randgap * a << endl;
                    arraynum--;                       
                }
                else{
                    output << startnum << endl;        // If choose to set sorted number, just normally do increment
                    startnum = startnum + randgap;
                }
            }
                int trigger = rand()%2;                // If choose to set unsorted number, Set a totally different number 
                if(trigger == 0 && arraynum!= 0){
                    output << rand()%1000 + startnum + randgap * a;                      
                }
                else{
                    output << startnum;        // If choose to set sorted number, just normally do increment
                }
    }
}

void SetSize(int a, int b, ofstream& output){
    srand((unsigned)time(NULL));                            // Set random
    if(a == 0){
        SetFile(10, b, output);                            // The file with 10 numbers
    }
    if(a == 1){
        SetFile(1000, b, output);
    }
    if(a == 2){
        SetFile(10000, b, output);
    }
    if(a == 3){
       SetFile(100000, b, output);
    }
}


int main(int argc, char* argv[]){

    string datalist[4][4] = {"0","1","2","3","0","1","2","3","0","1","2","3","0","1","2","3"};  // Create a 4 by 4 matrix

    for (int i = 0; i < 4; i++ ){
        for (int j = 0; j < 4; j++){
            ofstream outfile("List " + to_string(i) + "-" + to_string(j) + ".txt");    // Create ouput file with corresponding title
            if(!outfile){
            cout << "Problem occured" << endl;
            exit(0);
            }
            else{
                SetSize(i,j, outfile);                                           
            }
            outfile.close();
        }
    }


    return 0;
}

