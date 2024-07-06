class Solution {
public:
    int passThePillow(int n, int time) {

        int completedRounds=time/(n-1);
        int remainingSeconds=time%(n-1);

        //if(completedRounds==0) return remainingSeconds+1;

        if(completedRounds%2!=0) return n-remainingSeconds;
        else return remainingSeconds+1;

        
    }
};