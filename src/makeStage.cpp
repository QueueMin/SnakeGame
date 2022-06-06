#include <iostream>
#include <fstream>
#include <string>
#include "elements.cpp"

void makeStage(int stageNum, int stage[][MSIZE]) {
    std::string s = std::to_string(stageNum);
    std::string t = "stage" + s + ".txt";
    std::ifstream inputfile(t);

    if (!inputfile.is_open())
        std::cout << "Error opening file";

    // std::cout << t << "\n";
    for (int r = 0; r < MSIZE; r++)
    {
        for (int c = 0; c < MSIZE; c++)
        {
            inputfile >> stage[r][c];
        }
    }


    // // for debug
    // for (int r = 0; r < MSIZE; r++)
    // {
    //     for (int c = 0; c < MSIZE; c++)
    //     {
    //         std::cout << stage[r][c] << "\t";
    //     }
    //     std::cout << std::endl;
    // }
    // // for debug end
    
}

    


