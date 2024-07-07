class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int fullB=numBottles;
        int r=0;

        while(fullB>0){
            ans+=(long long) fullB;
            fullB=fullB+r;
             r=fullB%numExchange;
            fullB/=numExchange;
           
        }




        return ans;
        
    }
};