#include "elements.cpp"
#include <cstdlib>

class gateManager{
    private:
        int onStage;
        // gateA의 좌표를 각각 저장
        int gA_Y = DISABLED;
        int gA_X = DISABLED;
        // gateB의 좌표를 각각 저장
        int gB_Y = DISABLED;
        int gB_X = DISABLED;

        // 생성 후 뱀이 12칸 가면 사라지게 설계.
        // 이때, 뱀이 Gate에 들어온다면, tickLeft = 뱀의 길이.
        int tickLeft = 12;

    public:
        void searchGates(int stage[][MSIZE]){
            for (int i = 0; i < MSIZE; i++){
                for (int j = 0; j < MSIZE; j++){
                    int p = stage[i][j];
                    if (p == GATEa){
                        gA_Y = i; 
                        gA_X = j; 
                    }else if (p == GATEb){
                        gB_Y = i;
                        gB_X = j;
                    }
                }
            }
        }
        
        void spawnGate(int stage[][MSIZE]){
            while (gB_X != DISABLED){
                int ny, nx;
                if (gA_Y == DISABLED){
                    ny = rand()%MSIZE;
                    nx = rand()%MSIZE;

                    if (stage[ny][nx] == WALL){
                        stage[ny][nx] == GATEa;
                        gA_Y = ny;
                        gA_X = nx;
                    }else continue;

                    if (stage[ny][nx] == WALL){
                        stage[ny][nx] == GATEb;
                        gB_Y = ny;
                        gB_X = nx;
                    }else continue;
                }
                tickLeft = 12;
            }
        }

        gateManager(int stage[][MSIZE]){
            searchGates(stage);
            spawnGate(stage);
        }

        void setTickAsLen(Snake s){
            tickLeft = s.getBodyLen()+1;
        }

        void onNextStep(int stage[][MSIZE]){
            if (tickLeft == 0){
                stage[gA_Y][gA_X] = WALL;
                stage[gB_Y][gB_X] = WALL;
                gA_Y = gA_X = gB_Y = gB_X = DISABLED;
            }else{
                tickLeft--;
            }
        }

};
