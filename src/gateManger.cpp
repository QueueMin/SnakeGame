#include "elements.cpp"

class gateManaager{
    private:
        int onStage;
        // gateA의 좌표를 각각 저장
        int gA_Y = -1;
        int gA_X = -1;
        // gateB의 좌표를 각각 저장
        int gB_Y = -1;
        int gB_X = -1;

        // 생성 후 뱀이 12칸 가면 사라지게 설계.
        // 이때, 뱀이 들어오는 
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

        gateManaager(int stage[][MSIZE]){
            searchGates(stage);

        }
};
