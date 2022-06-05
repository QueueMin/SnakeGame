#include <iostream>

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


void displayOnTerminal(int stage[][MSIZE]){
    for (int i = 0; i < MSIZE; i++){
        for (int j = 0; j < MSIZE; j++){
            std::cout << stage[i][j];
        }
        std::cout << "\n";
    }

}