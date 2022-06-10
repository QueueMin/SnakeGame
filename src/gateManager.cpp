#include "elements.cpp"
#include <cstdlib>

class gateManager{
    private:
        // gateA의 좌표를 각각 저장
        int gA_Y = DISABLED;
        int gA_X = DISABLED;
        // gateB의 좌표를 각각 저장
        int gB_Y = DISABLED;
        int gB_X = DISABLED;

        // 생성 후 뱀이 tick만큼 가면 사라지게 설계.
        // 이때, 뱀이 Gate에 들어온다면, tick = 뱀의 길이.
        int tick = GATETICKINIT;

    public:
        gateManager(int stage[][MSIZE]){
            spawnGate(stage);
        }
        
        void spawnGate(int stage[][MSIZE]){
            int ny, nx;
            ny = rand()%MSIZE;
            nx = rand()%MSIZE;
            if (gA_Y == DISABLED){
                while(stage[ny][nx] != WALL){
                    ny = rand()%MSIZE;
                    nx = rand()%MSIZE;
                }
                stage[ny][nx] = GATEa;
                gA_Y = ny;
                gA_X = nx;
            }

            ny = rand()%MSIZE;
            nx = rand()%MSIZE;

            if (gB_Y == DISABLED){
                while(stage[ny][nx] != WALL){
                    ny = rand()%MSIZE;
                    nx = rand()%MSIZE;
                }
                stage[ny][nx] = GATEb;
                gB_Y = ny;
                gB_X = nx;
            }
        }

        void setTick(int l){
            tick = l;
        }

        void onNextStep(int stage[][MSIZE]){
            tick--;
            if (tick < 0){
                stage[gA_Y][gA_X] = WALL;
                stage[gB_Y][gB_X] = WALL;
                gA_Y = DISABLED;
                gA_X = DISABLED;
                gB_Y = DISABLED;
                gB_X = DISABLED;
                spawnGate(stage);
                setTick(GATETICKINIT);
            }
        }

};
