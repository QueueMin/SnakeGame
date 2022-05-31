#include <ncurses.h>
#include "makeStage.cpp"
#include "snake.cpp"



int main(){
    initscr();

    int stageLoaded[MSIZE][MSIZE];
    
    // int stageNum;
    // // for debug
    // std::cin >> stageNum;
    // makeStage(stageNum, stageLoaded);
    
    // for (int i = 0; i < MSIZE; i++){
    //     for (int j = 0; j < MSIZE; i++){
    //         std::cout << stageLoaded[i][j];
    //     }
    //     std::cout << "\n";
    // }
    char key;
    char userName[8];

    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    printw("user name: ");
    scanw("%s", userName);

    printw("%s", userName);
    refresh();

    getch();
    clear();
    refresh();
    
    getch();
    endwin();

    return 0;
}
