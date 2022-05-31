#include <ncurses.h>
#include "makeStage.cpp"



int main(){
    initscr();

    int stageLoaded[MSIZE][MSIZE];
    
    int stageNum;
    // for debug
    std::cin >> stageNum;
    makeStage(stageNum, stageLoaded);
    
    for (int i = 0; i < MSIZE; i++){
        for (int j = 0; j < MSIZE; i++){
            std::cout << stageLoaded[i][j];
        }
        std::cout << "\n";
    }

}
