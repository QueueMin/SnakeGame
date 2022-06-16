#include <ncurses.h>

#define MSIZE 21

void displayStage(int stage[][MSIZE]){
    start_color();
    init_pair(0,COLOR_BLACK,COLOR_BLACK);
    init_pair(1,COLOR_WHITE,COLOR_WHITE);
    init_pair(2,COLOR_WHITE,COLOR_WHITE);
    init_pair(3,COLOR_CYAN,COLOR_CYAN);
    init_pair(4,COLOR_BLUE,COLOR_BLUE);
    init_pair(5,COLOR_RED,COLOR_RED);
    init_pair(6,COLOR_GREEN,COLOR_GREEN);
    init_pair(7,COLOR_MAGENTA,COLOR_MAGENTA);
    init_pair(8,COLOR_MAGENTA,COLOR_MAGENTA);

    for (int i = 0; i < MSIZE; i++){
        for (int j = 0; j < MSIZE; j++){
            attron(COLOR_PAIR(stage[i][j]));
            printw("  ");
            attroff(COLOR_PAIR(stage[i][j]));
        }
        printw("\n");
    }
    refresh();
}