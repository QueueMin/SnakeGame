#include <iostream>
#include "elements.cpp"

void displayOnTerminal(int stage[][MSIZE]){
    for (int i = 0; i < MSIZE; i++){
        for (int j = 0; j < MSIZE; j++){
            std::cout << stage[i][j];
        }
        std::cout << "\n";
    }

}