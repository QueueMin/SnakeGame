
int dy[4] = {0, 0, 1, -1};  // 우, 좌, 상, 하
int dx[4] = {1, -1, 0, 0};  // 


class snake{
    private:
        int headVector = 1;
        int bodyLen = 3;
        
        int Y;
        int X;
    
    public:
        snake::snake(int y, int x){
            Y = y;
            X = x;
        }


        int getHeadVector(){
            return headVector;
        }
        
        int getBodyLen(){
            return bodyLen;
        }

        void setHeadVector(int a){
            headVector = a;
        }

        void setY(int y){
            Y = y;
        }

        void setX(int x){
            X = x;
        }

        bool isDead(){
            return bodyLen<=3;
        }

        int collideWith(int stage[][MSIZE]){
            return stage[Y+dy[headVector]][X+dx[headVector]];
        }


};