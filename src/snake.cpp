#include <deque>
#include <utility>
#include "elements.cpp"
#include "gateManager.cpp"

// snake head의 위치가 움직일 때 도움을 주는 배열 dy,dx.
int dy[4] = {-1, 0, 1, 0};  // 상, 우, 하, 좌
int dx[4] = {0, 1, 0, -1};  // 이렇게 하면 시계, 반시계, 반대쪽을 쉽게 구현가능

// snake의 필요한 정보를 저장하는 class snake
class Snake{
    private:
        int headVector = LEFT; // 머리가 향하는 방향. 항상 왼쪽을 바라보고 시작한다
        int bodyLen = 3; // 몸의 길이

        int life; // snake의 생존 유무
        int headY; // head의 현재 y 좌표
        int headX; // head의 현재 x 좌표
        
        // 몸 전체를 저장할 deque bodyDeque
        // 가장 앞에 있는 원소가 snake 객체의 head좌표가 된다.
        std::deque<std::pair<int, int>> bodyDeque;
    
    public:
        // void makeBodyDeque(int stage[][MSIZE]);
        // void findHead(int stage[][MSIZE]);
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
        // 생성자
        Snake(int stage[][MSIZE]){
            life = ALIVE;

            // 저장된 좌표를 기반으로 headY, headX값을 지정. 
            findHead(stage);
            makeBodyDeque();
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

        void moveHead(int stage[][MSIZE]){
            // 뱀이 한 칸 길어져 앞으로 가는 함수
            // 단, deque와 stage에 표시를 할 뿐 길이는 손대지 않는다.

            // 원래 머리였던 칸은 몸으로 표시한다.
            stage[headY][headX] = SBODY;

            // head의 좌표가 바라보는 방향 headVector를 기준으로 한칸 움직인다.
            // 이후 바뀐 좌표를 바탕으로 stage에 새 머리를 표시한다.
            headY = headY+dy[headVector];
            headX = headX+dx[headVector];
            stage[headY][headX] = SHEAD;

            // 이후 bodyDeque에 새 머리의 좌표를 추가
            bodyDeque.push_front(std::make_pair(headY, headX));
        }
        
        void gateHead(int stage[][MSIZE], int ny, int nx, gateManager gm){
            // 뱀이 gate를 탔을 때 head의 위치가 바뀌는 함수
            // 마찬가지로 길이는 손대지 않는다.
            // 도착지 게이트의 위치 ny와 nx를 추가로 받는다.
            
            //gateManager 객체의 남은 수명을 뱀의 길이만큼 연장시킨다.
            gm.setTickAsLen(*this);

            // 원래 머리였던 칸은 몸으로 표시한다.
            stage[headY][headX] = SBODY;

            // 도착 게이트를 바탕으로 머리의 좌표를 정한다.
            // 이후 바뀐 좌표를 바탕으로 stage에 새 머리를 표시한다.
            headY = ny + dy[headVector];
            headX = nx + dx[headVector];
            stage[headY][headX] = SHEAD;

            // 이후 bodyDeque에 새 머리의 좌표를 추가
            bodyDeque.push_front(std::make_pair(headY, headX));
        }

        void moveTail(int stage[][MSIZE]){
            // 뱀의 꼬리 한 칸이 줄어드는 함수
            // 위의 moveHead와 함께 사용하면, 이동 방향으로 뱀이 움직인 효과를 준다
            
            // 현재의 꼬리가 있는 좌표 저장
            int tailY = bodyDeque.back().first;
            int tailX = bodyDeque.back().second;
            
            //꼬리가 있던 곳은 빈칸으로 변한다.
            stage[tailY][tailX] = EMPTY;
            
            // deque에서 꼬리를 제거한다. 결과적으로, 꼬리가 움직이게 된 셈이다.
            bodyDeque.pop_back();
        }


        // 다음 칸에 무엇이 있을 지에 따라 snake의 상태를 조정하는 함수
        // 빈칸이면 좌표만 바뀐다.
        // poison 혹은 growth면, 길이도 바뀐다.
        // gateA면, gateB를 기반으로 이동한다.
        // gateB면, gateA를 기반으로 이동한다.  -->  Gate를 기반으로 좌표와 이동방향 지정해주는 함수 필요.
        // 남은 경우는 벽, 자신의 몸 뿐이다.(head가 head와 충돌하는 경우는 없으므로)
        // 벽과 몸이면, life를 DEAD로 바꾼다. 
        void changeOnNextStep(int stage[][MSIZE], gateManager gm){
            int next = collideWith(stage);
            
            if (next == EMPTY){
                // 다음칸이 빈 칸이면
                // 머리를 한칸, 꼬리를 한칸 움직인다.
                moveHead(stage);
                moveTail(stage);
                // 이전 꼬리의 좌표를 각각 저장
                 
            } else if (next == POISON){
                // 다음 칸이 독 아이템이면
                // 일단 길이가 1칸 줄어든다
                takePoison();
                // 만약 길이가 3보다 짧으면, 죽는다.
                if (bodyLen < 3) life = DEAD;
                // 머리를 한칸, 꼬리를 두칸 움직인다.(그래야 한칸 줄어든다.)
                moveHead(stage);
                moveTail(stage);
                moveTail(stage);
            } else if (next == GROWTH){
                // 다음 칸이 성장 아이템이면
                // 일단 길이가 1칸 늘어난다.
                takeGrowth();
                // 머리만 한칸 움직이면 된다.(그래야 한 칸 길어지게 된다.)
                moveHead(stage);
            } else if ((next == GATEa)||(next == GATEb)){
                // 찾아야 하는 GATE를 정한다(a인지 b인지)
                int findingGate;
                if (next == GATEa){
                    findingGate = GATEb;
                }else{
                    findingGate = GATEa;
                }

                // // for debug
                // std::cout << "going to " << findingGate << "\n";

                // stage에서 도착지인 findingGate를 찾는다
                // 도착지의 좌표는 ny, nx라 하자.
                int ny, nx;
                int flag = 0;
                for (int y = 0; y < MSIZE; y++){
                    if (flag) break;
                    for (int x = 0; x < MSIZE; x++){
                        if (stage[y][x] == findingGate){
                            ny = y; nx = x;
                            break;
                        }
                    }
                }
                
                // 탐색 완료
                // gate가 가장자리에 있다면, 즉 ny와 nx중 하나라도 0이거나 MSIZE라면
                if (((ny == 0)||(ny == MSIZE-1))||((nx == 0)||(nx == MSIZE-1))){
                    // 왼쪽에서 오른쪽, 위에서 아래...등과 같이 안쪽으로 진행한다.
                    // 진행방향은 headVector를 변경하여 변경된다.
                    if (ny == 0) {
                        // 도착지점이 윗 가장자리면, headVector는 아래로
                        headVector = DOWN;
                        // 이후 머리를 gate 이동 시키고, 꼬리를 한칸 움직인다.
                        gateHead(stage, ny, nx, gm);
                        moveTail(stage);
                    } else if (ny == MSIZE - 1){
                        // 도착지점이 아래 가장자리면, headVector는 위로
                        headVector = UP;
                        gateHead(stage, ny, nx, gm);
                        moveTail(stage);
                    } else if (nx == 0){
                        // 도착지점이 왼쪽 가장자리면, headVector는 오른쪽으로
                        headVector = RIGHT;
                        gateHead(stage, ny, nx, gm);
                        moveTail(stage);
                    }else if (nx == MSIZE - 1){
                        // 도착지점이 오른쪽 가장자리면, headVector는 왼쪽으로
                        headVector = LEFT;
                        gateHead(stage, ny, nx, gm);
                        moveTail(stage);
                    }

                } else {
                    // gate가 가장자리에 있는게 아니라면,
                    // 원래 방향, 시계, 역시계, 반대 순으로 시도
                    if (stage[ny+dy[headVector]][nx+dx[headVector]] == EMPTY){
                        // 원래 방향이 가능하다면,
                        // 벡터는 그대로 두고 이동.
                        gateHead(stage, ny, nx, gm);
                        moveTail(stage);
                    }else if (stage[ny+dy[(headVector+1)%4]][nx+dx[(headVector+1)%4]] == EMPTY){
                        // 시계방향이 가능하다면,
                        // 벡터를 시계방향으로 돌리고 이동
                        headVector = (headVector+1)%4;
                        gateHead(stage, ny, nx, gm);
                        moveTail(stage);
                    }else if (stage[ny+dy[(headVector+3)%4]][nx+dx[(headVector+3)%4]] == EMPTY){
                        // 반시계가 가능하다면,
                        // 벡터를 반시계방향으로 돌리고 이동
                        headVector = (headVector+3)%4;
                        gateHead(stage, ny, nx, gm);
                        moveTail(stage);
                    }else{
                        // 남은건 원래 진행방향의 반대방향뿐이다.
                        headVector = (headVector+2)%4;
                        gateHead(stage, ny, nx, gm);
                        moveTail(stage);
                    }
                }
            } else {
                // 이외의 경우,
                // 몸에 부딪히거나, 벽에 부딪히거나 둘 중 하나이다.
                // 딱히 아무것도 할 필요없고, 그냥 뱀이 죽으면 끝이다.
                life = DEAD;
            }
        }
        void getCord(){
            std::cout << "(" << headY << "," << headX << ")";
        }


        void changeHeadVector(char key){
            if (key == 'a'){
                headVector = LEFT;
            }else if (key == 'w'){
                headVector = UP;
            }else if (key == 'd'){
                headVector = RIGHT;
            }else if (key == 's'){
                headVector = DOWN;
            }else{
                return;
            }
        }


};