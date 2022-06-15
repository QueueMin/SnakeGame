
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
    
    char time[3];
    if (score.getTime() > 9){
        time[0] = score.getTime() / 10 + '0';
        time[1] = score.getTime() % 10 + '0';
        time[2] = '\0';
    }else{
        time[0] = score.getTime() % 10 + '0';
        time[1] = '\0';
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
    mvwprintw(realScore, 5, 1, "T: ");
    mvwprintw(realScore, 5, 4, time);
    wborder(realScore, '|', '|', '-', '-', '*', '*', '*', '*');
    wrefresh(realScore);
}


void drawGoalScore(WINDOW *goalScore, scoreBoard& score){
    char growth[7];
    if (score.getGoalGrowth() > 9){
        growth[0] = score.getGoalGrowth() / 10 + '0';
        growth[1] = score.getGoalGrowth() % 10 + '0';
        growth[2] = ' ';
    }else{
        growth[0] = score.getGoalGrowth() % 10 + '0';
        growth[1] = ' ';
        growth[2] = ' ';
    }
    growth[3] = '(';
    growth[5] = ')';
    if (score.isClearGrowth()){
        growth[4] = 'O';
    }else{
        growth[4] = ' ';
    }
    growth[6] = '\0';

    char poison[7];
    if (score.getGoalPoison() > 9){
        poison[0] = score.getGoalPoison() / 10 + '0';
        poison[1] = score.getGoalPoison() % 10 + '0';
        poison[2] = ' ';
    }else{
        poison[0] = score.getGoalPoison() % 10 + '0';
        poison[1] = ' ';
        poison[2] = ' ';
    }
    poison[3] = '(';
    poison[5] = ')';
    if (score.isClearPoison()){
        poison[4] = 'O';
    }else{
        poison[4] = ' ';
    }
    poison[6] = '\0';
    
    char len[7];
    if (score.getGoalLen() > 9){
        len[0] = score.getGoalLen() / 10 + '0';
        len[1] = score.getGoalLen() % 10 + '0';
        len[2] = ' ';
    }else{
        len[0] = score.getGoalLen() % 10 + '0';
        len[1] = ' ';
        len[2] = ' ';
    }
    len[3] = '(';
    len[5] = ')';
    if (score.isClearLen()){
        len[4] = 'O';
    }else{
        len[4] = ' ';
    }
    len[6] = '\0';
    
    char gate[7];
    if (score.getGoalGate() > 9){
        gate[0] = score.getGoalGate() / 10 + '0';
        gate[1] = score.getGoalGate() % 10 + '0';
        gate[2] = ' ';
    }else{
        gate[0] = score.getGoalGate() % 10 + '0';
        gate[1] = ' ';
        gate[2] = ' ';
    }
    gate[3] = '(';
    gate[5] = ')';
    if (score.isClearGate()){
        gate[4] = 'O';
    }else{
        gate[4] = ' ';
    }
    gate[6] = '\0';
    
    char time[7];
    if (score.getGoalTime() > 9){
        time[0] = score.getGoalTime() / 10 + '0';
        time[1] = score.getGoalTime() % 10 + '0';
        time[2] = ' ';
    }else{
        time[0] = score.getGoalTime() % 10 + '0';
        time[1] = ' ';
        time[2] = ' ';
    }
    time[3] = '(';
    time[5] = ')';
    if (score.isClearTime()){
        time[4] = 'O';
    }else{
        time[4] = ' ';
    }
    time[6] = '\0';


    init_pair(9, COLOR_WHITE, COLOR_BLACK);
    wbkgd(goalScore, COLOR_PAIR(9));
    wattron(goalScore, COLOR_PAIR(9));

    mvwprintw(goalScore, 1, 1, "Mission");
    mvwprintw(goalScore, 2, 1, "B: ");
    mvwprintw(goalScore, 2, 4, len);
    mvwprintw(goalScore, 3, 1, "+: ");
    mvwprintw(goalScore, 3, 4, growth);
    mvwprintw(goalScore, 4, 1, "-: ");
    mvwprintw(goalScore, 4, 4, poison);
    mvwprintw(goalScore, 5, 1, "G: ");
    mvwprintw(goalScore, 5, 4, gate);
    mvwprintw(goalScore, 6, 1, "T: ");
    mvwprintw(goalScore, 6, 4, time);
    wborder(goalScore, '|', '|', '-', '-', '*', '*', '*', '*');
    wrefresh(goalScore);
}