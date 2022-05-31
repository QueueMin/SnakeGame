
int dy[4] = {0, 0, 1, -1};  // 우, 좌, 상, 하
int dx[4] = {1, -1, 0, 0};  // 


class snake{
    private:
        int headVector;
        int bodyLen;
        
        int Y;
        int X;
    
    public:
        int getHeadVector(){
            return headVector;
        }
        
        int getBodyLen(){
            return bodyLen;
        }


};