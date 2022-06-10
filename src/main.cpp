#include <ncurses.h>
#include <time.h>
#include <unistd.h>

#include "makeStage.cpp"
#include "snake.cpp"
#include "displayStage.cpp"

#include "displayOnTerminal.cpp" // for debug

#define sleep(t) usleep(t)


int main(){
    srand(time(NULL));
    initscr();
    resize_term(30, 90);
    
    noecho();
    curs_set(0);
    nodelay(stdscr, true);

    int stageLoaded[MSIZE][MSIZE];

    int stageNum = 1;
    makeStage(stageNum, stageLoaded);
    while (stageNum <= 4){
        Snake s = Snake(stageLoaded);
        gateManager gm = gateManager(stageLoaded);
        char key;

        // snake 내의 method들이 작동해야하는 순서는
        // 오직 다음 순간만을 기준으로 생각하여 작동시킨다.
        // 뱀이 살아있는 동안,
        // 1. 키입력을 바탕으로 머리의 방향을 바꾼다. 입력 없으면 유지.
        // 2. 현재 머리의 방향을 기준으로 도착한 다음칸에 도착 시 일어날 변화 반영
        bool flag = false;
        while (!s.isDead()){
            //input
            sleep(250000);
            key = getch();
            
            //logics
            s.changeHeadVector(key);
            s.changeOnNextStep(stageLoaded, gm);
            gm.onNextStep(stageLoaded);
            
            //display
            move(0,0);
            displayStage(stageLoaded);
        }
        getch();
        if (flag){
            stageNum++;
            makeStage(stageNum, stageLoaded);
            sleep(BEFORENEXTSTAGE);
            continue;
        }else{
            break;
        }
    }
    endwin();
    return 0;
}
