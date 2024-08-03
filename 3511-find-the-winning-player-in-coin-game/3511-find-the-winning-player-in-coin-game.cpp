class Solution {
public:
    string losingPlayer(int x, int y) {

        int turn=min(x,y/4);

        if(turn&1) return "Alice";
        return "Bob";
        
    }
};