class Solution {

    //returns maxProfit from i th index and canBuy or not by problem constraints 
    int solve(int i,int canBuy,vector<int>& prices,vector<vector<int>>& dp){

        if(i>=prices.size()) return 0;

        if(dp[i][canBuy]!=-1) return dp[i][canBuy];


        int profit=0;  //no buy sell so profit is zero initially

        if(canBuy){

            int buy= -prices[i]+solve(i+1,!canBuy,prices,dp);
            int notBuy=0+solve(i+1,canBuy,prices,dp);

            profit=max(buy,notBuy);

        }
        else{

            int sell= prices[i]+solve(i+1,!canBuy,prices,dp);
            int notSell=0+solve(i+1,canBuy,prices,dp);

            profit=max(sell,notSell);


        }

        return dp[i][canBuy]=profit;

    }



public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return solve(0,1,prices,dp);
    }
};