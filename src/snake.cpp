# define DEAD 0
# define ALIVE 1

#define EMPTY 0
#define WALL 1
#define IWALL 2
#define SHEAD 3
#define SBODY 4
#define GROWTH 5
#define POISON 6
#define GATEa 7
#define GATEb 8

#include <deque>
#include <utility>

// snake head의 위치가 움직일 때 도움을 주는 배열 dy,dx.
int dy[4] = {0, 0, 1, -1};  // 우, 좌, 상, 하
int dx[4] = {1, -1, 0, 0};  // 

// snake의 필요한 정보를 저장하는 class snake
class snake{
    private:
        int headVector = 1; // 머리가 향하는 방향. 항상 왼쪽을 바라보고 시작한다
        int bodyLen = 3; // 몸의 길이

        int life; // snake의 생존 유무
        int headY; // head의 현재 y 좌표
        int headX; // head의 현재 x 좌표
        
        // 몸 전체를 저장할 deque bodyDeque
        // 가장 앞에 있는 원소가 snake 객체의 head좌표가 된다.
        std::deque<std::pair<int, int>> bodyDeque;
    
    public:
        void makeBodyDeque(int stage[][MSIZE]);
        void findHead(int stage[][MSIZE]);
        // 생성자
        snake::snake(int stage[][MSIZE]){
            // y 좌표와 x 좌표를 인자로 받아 생성.

            life = ALIVE;

            // 저장된 좌표를 기반으로 headY, headX값을 지정. 
            findHead(stage);
            makeBodyDeque();
        }


        void findHead(int stage[][MSIZE]){
            for (int i = 0; i < MSIZE; i++){
                for (int j = 0; j < MSIZE; j++){
                    if ((stage[i][j] == SHEAD)){
                        headY = i;
                        headX = j;
                        return;
                    }
                }
            }
        }


        void makeBodyDeque(){
            bodyDeque.push_back(std::make_pair(headY, headX));
            bodyDeque.push_back(std::make_pair(headY, headX+1));
            bodyDeque.push_back(std::make_pair(headY, headX+2));
        }

        // headVector값을 return
        int getHeadVector(){
            return headVector;
        }
        
        // 몸의 길이를 return
        int getBodyLen(){
            return bodyLen;
        }

        // headVector값을 지정
        void setHeadVector(int a){
            headVector = a;
        }

        // snake의 Y값 지정
        void setY(int y){
            headY = y;
        }

        // snake의 X값 지정
        void setX(int x){
            headX = x;
        }

        // snake의 Y, X값 지정.
        void setCord(int y, int x){
            setY(y);
            setX(x);
        }

        // snake가 죽었는지 return
        bool isDead(){
            return !life;
        }

        // 독 아이템 섭취 시
        void takePoison(){
            bodyLen--;
        }

        // 성장 아이템 섭취 시
        void takeGrowth(){
            bodyLen++;
        }

        // 현재 headY, headX, headVector값을 바탕으로,
        // 다음 칸에 갔을 때 무엇과 부딪히는지 return해주는 함수
        int collideWith(int stage[][MSIZE]){
            return stage[headY+dy[headVector]][headX+dx[headVector]];
        }

        // 다음 칸에 무엇이 있을 지에 따라 snake의 상태를 조정하는 함수
        // 빈칸이면 좌표만 바뀐다.
        // poison 혹은 growth면, 길이도 바뀐다.
        // gateA면, gateB를 기반으로 이동한다.
        // gateB면, gateA를 기반으로 이동한다.  -->  Gate를 기반으로 좌표와 이동방향 지정해주는 함수 필요.
        // 남은 경우는 벽, 자신의 몸 뿐이다.(head가 head와 충돌하는 경우는 없으므로)
        // 벽과 몸이면, life를 DEAD로 바꾼다. 
        void changeOnNextStep(int stage[][MSIZE]){
        }



};