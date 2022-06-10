
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

    public:
        scoreBoard(int gate, int grow, int poison, int len, int time){
            goalGate = gate;
            goalGrowth = grow;
            goalPoison = poison;
            goalLen = len;
            goalTime = time;
        }

        void updateGate(int g){
            realGate = g;
        }
        void updateGrowth(int g){
            realGrowth = g;
        }
        void updatePoison(int p){
            realPoison = p;
        }
        void updateLen(int l){
            realLen = l;
        }
        void updateRecordLen(int rl){
            realRecordLen = rl;
        }
        void updateTime(int t){
            realTime = t;
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


        

};