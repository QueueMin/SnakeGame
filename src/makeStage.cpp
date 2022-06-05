#include <iostream>
#include <fstream>

#define MSIZE 21

void makeStage(int stageNum, int stage[][MSIZE]){
    #include<iostream>
#include<fstream>
#include<string>
#define MSIZE 21
using namespace std;
void makeStage(int stageNum, int stage[][MSIZE]) {
    string s = to_string(stageNum);
    string t = "stage" + s + ".txt";
    int row = sizeof(stage) / sizeof(stage[0]);
    ifstream inputfile(t);

    if (!inputfile.is_open())
        cout << "Error opening file";

    for (int r = 0; r < MSIZE; r++)
    {
        for (int c = 0; c < MSIZE; c++)
        {
            inputfile >> stage[r][c];
        }
    }

    for (int r = 0; r < MSIZE; r++)
    {
        for (int c = 0; c < MSIZE; c++)
        {
            cout << stage[r][c] << "\t";
        }
        cout << endl;
    }
    
}

    


