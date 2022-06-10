#include "elements.cpp"
#include <cstdlib>
#include <queue>
#include <utility>



class itemManager{
    private:
        int dy[4] = {-1, 1, 0, 0};
        int dx[4] = {0, 0, 1, -1};
        int itemCount = 0;
        
        int period = ITEMPERIOD;
        std::queue<std::pair<int, int>> delQ;


    public:
        itemManager(int stage[][MSIZE]){
            addItem(stage);
        }

        void addItem(int stage[][MSIZE]){
            if (itemCount == 3){
                return;
            }
            int ny = 0, nx = 0;

            while (stage[ny][nx] != EMPTY){
                ny = rand()%MSIZE;
                nx = rand()%MSIZE;
                
                if (!(isGateNear(stage, ny, nx))){
                    continue;
                }
            }
            stage[ny][nx] = randItem();
            
            delQ.push(std::make_pair(ny, nx));
            itemCount++;
        }


        int randItem(){
            return GROWTH+rand()%2;
        }


        void delItem(int stage[][MSIZE]){
            if (delQ.empty()){
                return;
            }
            if (delQ.size() == 3){
                int ny = delQ.front().first;
                int nx = delQ.front().second;
                delQ.pop();

                stage[ny][nx] = EMPTY;
                itemCount--;
            }
        }


        int isGateNear(int stage[][MSIZE], int y, int x){
            int ny, nx;
            int flag = 0;
            for (int i = 0; i < 4; i++){
                ny = y + dy[i];
                nx = x + dx[i];
                if (ny < 0) continue;
                if (nx < 0) continue;
                if (ny > MSIZE) continue;
                if (nx > MSIZE) continue;

                if ((stage[ny][nx] == GATEa) or (stage[ny][nx] == GATEb)){
                    flag = 1;
                }
            }
            return flag;
        }

        void changeOnNextStep(int stage[][MSIZE]){
            if (--period) return;
            delItem(stage);
            addItem(stage);
            period = ITEMPERIOD;
        }

};
