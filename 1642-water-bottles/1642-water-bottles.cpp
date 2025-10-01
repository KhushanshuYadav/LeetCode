class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int ans=numBottles;

        while(numBottles>=numExchange){
            int youGet=numBottles/numExchange;
            ans+=youGet;
            int leftAtyou=numBottles%numExchange;
            numBottles=youGet+leftAtyou;
        }
        return ans;
    }
};