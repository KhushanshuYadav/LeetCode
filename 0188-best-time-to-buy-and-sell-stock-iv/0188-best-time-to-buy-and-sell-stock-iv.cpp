class Solution {
    int solve(int i, int canBuy, vector<int>& prices, int tCount , vector<vector<vector<int>>>& dp,int &k) {

        if(tCount>=k) return 0;


        

        if (i >= prices.size()) return 0;
            
        
        if(dp[i][canBuy][tCount]!=-1) return dp[i][canBuy][tCount];
        
       
        

        int profit = 0; // no buy sell so profit is zero initially

        if (canBuy) {

            int buy = -prices[i] + solve(i + 1, 0, prices,tCount, dp,k);
            int notBuy = 0 + solve(i + 1, 1, prices, tCount,dp,k);

            profit = max(buy, notBuy);

        } else {

            int sell = prices[i] + solve(i + 1, 1, prices,tCount+1, dp,k);
            int notSell = 0 + solve(i + 1, 0, prices,tCount ,dp,k);

            profit = max(sell, notSell);
        }

        return dp[i][canBuy][tCount] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();


        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k,-1)));

        return solve(0,1,prices,0,dp,k);
        
    }
};