
class scoreBoard{
    private:
        int goalGate;
        int goalGrowth;
        int goalPoison;
        int goalLen;
        int goalTime;

        int realGate = 0;
        int realGrowth = 0;
        int realPoison = 0;
        int realLen = 3;
        int realRecordLen = 3;
        int realTime = 0;

        int clearGate = 0;
        int clearGrowth = 0;
        int clearPoison = 0;
        int clearLen = 0;
        int clearTime = 0;
    public:
        scoreBoard(int gate, int grow, int poison, int len, int time){
            goalGate = gate;
            goalGrowth = grow;
            goalPoison = poison;
            goalLen = len;
            goalTime = time;
        }
        scoreBoard(int stageInfo[5]){
            goalGate = stageInfo[0];
            goalGrowth = stageInfo[1];
            goalPoison = stageInfo[2];
            goalLen = stageInfo[3];
            goalTime = stageInfo[4];
        }

        void updateGate(int g){
            realGate = g;
            if (realGate >= goalGate) clearGate = 1;
        }
        void updateGrowth(int g){
            realGrowth = g;
            if (realGrowth >= goalGrowth) clearGrowth = 1;
        }
        void updatePoison(int p){
            realPoison = p;
            if (realPoison >= goalPoison) clearPoison = 1;
        }
        void updateLen(int l){
            realLen = l;
            if (realLen >= goalLen) clearLen = 1;
        }
        void updateRecordLen(int rl){
            realRecordLen = rl;
        }
        void updateTime(int t){
            realTime = t/4;
            if (realTime >= goalTime) clearTime = 1;
        }

        void updateAll(int ga, int gr, int p, int l, int rl, int t){
            updateGate(ga);
            updateGrowth(gr);
            updatePoison(p);
            updateLen(l);
            updateRecordLen(rl);
            updateTime(t);
        }

        int getGate(){
            return realGate;
        }
        int getGrowth(){
            return realGrowth;
        }
        int getPoison(){
            return realPoison;
        }
        int getLen(){
            return realLen;
        }
        int getRecordLen(){
            return realRecordLen;
        }
        int getTime(){
            return realTime;
        }
        
        
        int getGoalGate(){
            return goalGate;
        }
        int getGoalGrowth(){
            return goalGrowth;
        }
        int getGoalPoison(){
            return goalPoison;
        }
        int getGoalLen(){
            return goalLen;
        }
        int getGoalTime(){
            return goalTime;
        }
        
        int isClearGate(){
            return clearGate;
        }
        int isClearGrowth(){
            return clearGrowth;
        }
        int isClearPoison(){
            return clearPoison;
        }
        int isClearLen(){
            return clearLen;
        }
        int isClearTime(){
            return clearTime;
        }


        int isClearStage(){
            return clearGate&clearGrowth&clearPoison&clearLen&clearTime;
        }
        

};