#include <ncurses.h>

#define MSIZE 21

#define EMPTY 0  // 빈 곳은 검게
#define WALL 1  // 벽은 하얗게
#define IWALL 2  // I벽도 하얗게
#define SHEAD 3 // 뱀머리는 하늘
#define SBODY 4 // 몸은 파랑
#define GROWTH 5 // 성장약은 초록
#define POISON 6 // 독은 빨강
#define GATEa 7 // GATEa는 자홍
#define GATEb 8 // GATEb도 자홍


void displayStage(int stage[][MSIZE]){
    start_color();
    init_pair(0,COLOR_BLACK,COLOR_BLACK);
    init_pair(1,COLOR_WHITE,COLOR_WHITE);
    init_pair(2,COLOR_WHITE,COLOR_WHITE);
    init_pair(3,COLOR_CYAN,COLOR_CYAN);
    init_pair(4,COLOR_BLUE,COLOR_BLUE);
    init_pair(5,COLOR_GREEN,COLOR_GREEN);
    init_pair(6,COLOR_RED,COLOR_RED);
    init_pair(7,COLOR_MAGENTA,COLOR_MAGENTA);
    init_pair(8,COLOR_MAGENTA,COLOR_MAGENTA);
    for (int i = 0; i < MSIZE; i++){
        for (int j = 0; j < MSIZE; j++){
            attron(COLOR_PAIR(stage[i][j]));
            printw("  ");
        }
    }
    refresh();
}