
#include <ncurses.h>
#include <string>

#include "scoreBoards.cpp"


void drawRealScore(WINDOW *realScore, scoreBoard& score){
    char growth[3];
    if (score.getGrowth() > 9){
        growth[0] = score.getGrowth() / 10 + '0';
        growth[1] = score.getGrowth() % 10 + '0';
        growth[2] = '\0';
    }else{
        growth[0] = score.getGrowth() % 10 + '0';
        growth[1] = '\0';
    }

    char poison[3];
    if (score.getPoison() > 9){
        poison[0] = score.getPoison() / 10 + '0';
        poison[1] = score.getPoison() % 10 + '0';
        poison[2] = '\0';
    }else{
        poison[0] = score.getPoison() % 10 + '0';
        poison[1] = '\0';
    }
    
    char len[3];
    if (score.getLen() > 9){
        len[0] = score.getLen() / 10 + '0';
        len[1] = score.getLen() % 10 + '0';
        len[2] = '\0';
    }else{
        len[0] = score.getLen() % 10 + '0';
        len[1] = ' ';
        len[2] = '\0';
    }
    
    char recordLen[3];
    if (score.getRecordLen() > 9){
        recordLen[0] = score.getRecordLen() / 10 + '0';
        recordLen[1] = score.getRecordLen() % 10 + '0';
        recordLen[2] = '\0';
    }else{
        recordLen[0] = score.getRecordLen() % 10 + '0';
        recordLen[1] = ' ';
        recordLen[2] = '\0';
    }
    
    char gate[3];
    if (score.getGate() > 9){
        gate[0] = score.getGate() / 10 + '0';
        gate[1] = score.getGate() % 10 + '0';
        gate[2] = '\0';
    }else{
        gate[0] = score.getGate() % 10 + '0';
        gate[1] = '\0';
    }
    
    init_pair(9, COLOR_WHITE, COLOR_BLACK);
    wbkgd(realScore, COLOR_PAIR(9));
    wattron(realScore, COLOR_PAIR(9));

    mvwprintw(realScore, 1, 1, "B: ");
    mvwprintw(realScore, 1, 4, len);
    mvwprintw(realScore, 1, 6, "/");
    mvwprintw(realScore, 1, 7, recordLen);
    mvwprintw(realScore, 2, 1, "+: ");
    mvwprintw(realScore, 2, 4, growth);
    mvwprintw(realScore, 3, 1, "-: ");
    mvwprintw(realScore, 3, 4, poison);
    mvwprintw(realScore, 4, 1, "G: ");
    mvwprintw(realScore, 4, 4, gate);
    wborder(realScore, '|', '|', '-', '-', '*', '*', '*', '*');
    wrefresh(realScore);
}