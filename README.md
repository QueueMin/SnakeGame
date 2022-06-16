# 2022-1 C++프로그래밍 팀 프로젝트
## SnakeGame
https://github.com/QueueMin/SnakeGame

### 3분반 14조
#### 20191555 김규민
#### 20203041 김성호
#### 20203058 노혜원

### 개발 환경: Ubuntu 20.04.4

### 플레이 방법
```
git clone https://github.com/QueueMin/SnakeGame.git
cd SnakeGame/src
./game
```
#### 혹은 컴파일 필요 시
```
sudo apt-get update
sudo apt-get install libncurses5-dev libncursesw5-dev

git clone https://github.com/QueueMin/SnakeGame.git

cd SnakeGame/src
g++ -o game main.cpp -l ncurses
./game
```


---
* 구현하고자 하는 UI

![image](https://user-images.githubusercontent.com/55120768/171079283-c9e52a0f-e261-4c2e-be73-d7e1fea0d921.png)

---
### 구현사항#1
![image](https://user-images.githubusercontent.com/55120768/171079810-99ecfed6-a38d-45a2-a17c-e1b40c2a2b88.png)
* Snake는 진행방향의 반대방향으로 이동할 수 없다. 위의 경우, Head가 진행방향이다.
    * 진행방향과 같은 방향키 입력은 무시된다.
    * 방향키는 사용자의 입력을 받는다. 방향키 입력 시 방향키의 방향으로 Head의 진행방향이 변경된다.
    * Head 방향 이동은 일정시간(0.5초)마다 진행된다.
* Head 방향과 반대되는 방향으로 이동 시 Game Over가 선언된다.
---
### 구현사항#2
![image](https://user-images.githubusercontent.com/55120768/171080581-dd612324-97e4-4e6f-bce2-bf664f15de63.png)
* Snake는 Head를 통하여 Item을 획득할 수 있다.
* Item은 두 종류이며, 각각 Growth, Poison이다.
    * Growth를 획득한 경우, 몸의 길이가 1 증가한다.
    * Poison을 획득한 경우, 몸의 길이가 1 감소한다. 이때, 몸의 길이가 3보다 작아지면 Game Over가 선언된다.
* Item은 SnakeBody가 있지 않은 임의의 위치에 출현한다.
* 출현 후 일정시간이 지나면 사라지고, 다른 위치에 나타나야 한다.
* 동시에 존재할 수 있는 Item의 개수는 최대 3개이다.
---
### 구현사항#3
![image](https://user-images.githubusercontent.com/55120768/171081375-136d5b33-bdaf-4ae3-9719-84e3be3efa7a.png)
* Gate는 두 개가 한 쌍이며, 동시에 존재할 수 있는 Gate의 개수는 최대 1개이다.
* 한 쌍의 Gate는 서로 다른 곳에 존재해야한다.
* 임의의 Wall에서 나타난다.
* Gate에 Snake가 진입하면, 다른 Gate로 진출한다.
* Gate에 Snake가 진입중인 경우, Gate는 사라지지 않으며 다른 위치에서 Gate가 나타나지 않는다.
---
### 구현사항#4
![image](https://user-images.githubusercontent.com/55120768/171081913-37fcbe89-8c75-4094-b3f2-97bea56a2fe2.png)
* Gate가 나타나는 벽이 가장자리에 있을 때, Gate를 타면 Snake는 항상 안쪽 방향으로 진출한다.
    * 상단 벽은 아래로, 하단 벽은 위로... 같은 방식으로 진출한다.
* Gate가 나타나는 벽이 Map의 가운데 있다면,
    * 진입 방향과 일치하는 방향으로 진출을 시도한다
    * 불가능하다면, 진입 방향의 시계방향으로 회전하는 방향으로 진출을 시도한다.
    * 그 또한 불가능하다면, 진입 방향의 역시계방향으로 회전하는 방향으로 진출을 시도한다.
    * 그 또한 불가능 하다면, 진입 방향의 반대 방향으로 진출한다.
---
### 구현사항#5
![image](https://user-images.githubusercontent.com/55120768/171082731-ba4e27bb-0026-46e8-ba96-d83c80a20474.png)
* Wall
    * Snake가 통과할 수 없는 벽이며, 충돌 시 Game Over가 선언된다.
    * Gate로 변할 수 있다.
* Immune Wall
    * Wall과 특성이 같지만 Gate로 변할 수 없다.
* Wall에 Gate가 출현하는 방법은 임의로 결정한다.
---
### 구현사항#6
![image](https://user-images.githubusercontent.com/55120768/171084799-be8ef67a-e06d-41e8-b362-1fefb00d5560.png)
* 각 분야별로 정해진 목표 점수를 달성하면, 해당 게임이 종료되고 다음 게임으로 넘어갈 수 있게 한다.
* 분야별 점수와 그 계산 방법은 다음과 같다.
    * B: (현재 몸 길이)/(최대 몸 길이)
    * + : 해당 게임 중 획득한 Growth의 수
    * - : 해당 게임 중 획득한 Poinson의 수
    * Gate : 해당 게임 중 통과한 Gate의 수
    * T : 해당 게임을 플레이한 시간(초 단위로 계산)
* 점수는 Map을 보여주는 화면 오른쪽에 ScoreBoard의 형태로 표시한다.
* 각 분야별 목표 점수는 ScoreBoard 아래에 표시한다.
    * 목표 달성 여부를 직관적으로 확인할 수 있도록 한다.
---
### 구현사항#7
* 한 게임은 하나의 Stage형태로 플레이되며, 최소 4개의 Stage가 존재해야 한다.
* 각 Stage의 Map은 서로 달라야 한다.
