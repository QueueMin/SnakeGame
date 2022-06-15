#include <ncurses.h>
#include <time.h>
#include <unistd.h>

#include "makeStage.cpp"
#include "snake.cpp"
#include "displayStage.cpp"
#include "drawScore.cpp"

#define sleep(t) usleep(t)


int main(){
    srand(time(NULL));
    initscr();
    resize_term(30, 90);
    WINDOW* realScore;
    realScore = newwin(8, 20, 1, 48);
    wbkgd(realScore, 2);
    wrefresh(realScore);

    WINDOW* goalScore;
    init_pair(3, COLOR_YELLOW, COLOR_BLUE);
    goalScore = newwin(8, 20, 9, 48);
    wbkgd(goalScore, 3);
    wrefresh(goalScore);

    refresh();
    
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
    keypad(stdscr, true);

    int stageLoaded[MSIZE][MSIZE];

    int stageNum = 1;
    int mission[5][5] =
        {
        // G, +, -, Len, T
            {0, 0, 0, 0, 0},
            {1, 3, 3, 6, 10},
            {3, 3, 3, 7, 10},
            {5, 2, 2, 5, 20},
            {0, 7, 0, 10, 60}
        };
    makeStage(stageNum, stageLoaded);
    while (stageNum <= 4){
        Snake s = Snake(stageLoaded);
        gateManager gm = gateManager(stageLoaded);
        itemManager im = itemManager(stageLoaded);
        scoreBoard sc = scoreBoard(mission[stageNum]);
        int vin;

        // snake 내의 method들이 작동해야하는 순서는
        // 오직 다음 순간만을 기준으로 생각하여 작동시킨다.
        // 뱀이 살아있는 동안,
        // 1. 키입력을 바탕으로 머리의 방향을 바꾼다. 입력 없으면 유지.
        // 2. 현재 머리의 방향을 기준으로 도착한 다음칸에 도착 시 일어날 변화 반영
        bool flag = false;
        while (!s.isDead()){
            //input
            sleep(250000);
            vin = getch();
            switch (vin){
                case KEY_LEFT:
                    vin = 'a'; 
                    break;
                case KEY_RIGHT:
                    vin = 'd'; 
                    break;
                case KEY_UP:
                    vin = 'w'; 
                    break;
                case KEY_DOWN:
                    vin = 's'; 
                    break;
            }


            gm.changeOnNextStep(stageLoaded);

            im.changeOnNextStep(stageLoaded);

            s.changeHeadVector(vin);
            s.changeOnNextStep(stageLoaded, gm, im);
            
            sc.updateAll(s.getGateScore(), s.getGrowthScore(), s.getPoisonScore(), s.getBodyLen(), s.getLenRecordScore(), s.getTimeScore());

            //display
            move(0,0);
            displayStage(stageLoaded);
            drawRealScore(realScore, sc);
            drawGoalScore(goalScore, sc);
            
            
            flag = sc.isClearStage();
            if (flag) break;
        }
        if (flag){
            if (stageNum == 4) continue;
            mvprintw(10, 1, "Stage clear. Get ready for next stage...");
            refresh();
            stageNum++;
            makeStage(stageNum, stageLoaded);
            sleep(BEFORENEXTSTAGE);
            continue;
        }else{
            nodelay(stdscr, false);
            mvprintw(10, 4, "Game Over. Press any key to exit....");
            getch();
            break;
        }
    }
    if (stageNum == 5){
        clear();
        nodelay(stdscr, false);
        mvprintw(10, 1, "Congratulations! All stage cleared!");
        mvprintw(11, 5, "Press ANY key to exit....");
        refresh();
        getch();
    }

    endwin();
    return 0;
}
