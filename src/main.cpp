#include <ncurses.h>
#include <time.h>
#include "makeStage.cpp"
#include "snake.cpp"
#include "displayStage.cpp"

#include "displayOnTerminal.cpp" // for debug



int main(){

    int stageLoaded[MSIZE][MSIZE];
    
    // for debug
    int stageNum;
    std::cin >> stageNum;
    makeStage(stageNum, stageLoaded);
    
    // for (int i = 0; i < MSIZE; i++){
    //     for (int j = 0; j < MSIZE; j++){
    //         std::cout << stageLoaded[i][j];
    //     }
    //     std::cout << "\n";
    // }
    // for debug end

    // // for debug
    // std::string a = "211111111111111111112100000000000000000001100000000000000500001800000000000000000007100000000000000000001100000000000000000001100000000000000000001100000000000000000001100000000000000000001100000000505050500001100000003440000000001100000000000000000001100000000000000000001100000000000000000001100000000066600000001100000000000000000001100000000000000000001100000000000000000001100000000000000000001100000000000000000001211111111111111111112";
    // for (int i = 0; i < MSIZE; i++){
    //     for (int j = 0; j < MSIZE; j++){
    //         char t = a[i*MSIZE+j];
    //         stageLoaded[i][j] =  t - '0';
    //     }
    // }
    // // for debug end

    // for check snake move
    resize_term(30, 90);
    initscr();

    while (true){
        Snake s = Snake(stageLoaded);
        char key;

        // snake 내의 method들이 작동해야하는 순서는
        // 오직 다음 순간만을 기준으로 생각하여 작동시킨다.
        // 뱀이 살아있는 동안,
        // 1. 키입력을 바탕으로 머리의 방향을 바꾼다. 입력 없으면 유지.
        // 2. 현재 머리의 방향을 기준으로 도착한 다음칸에 도착 시 일어날 변화 반영
        while (!s.isDead()){
            // displayOnTerminal(stageLoaded);
            // clear();
            move(0,0);
            displayStage(stageLoaded);
            
            std::cin >> key;
            std::cout << "\n";

            s.changeHeadVector(key);
            s.changeOnNextStep(stageLoaded);
        }
        break;
    }
    endwin();
    std::cout << "Game Over\n";
    getchar();
    // for check snake move end

    return 0;
}
