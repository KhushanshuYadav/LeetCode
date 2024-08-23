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


       vector<vector<int>> next(2, vector<int>(k+1, 0));
       vector<vector<int>> curr(2, vector<int>(k+1, 0));

       

       
        next[0][k] = 0;
        next[1][k] = 0;

        curr[0][k] = 0;
        curr[1][k] = 0;
        

        for (int i = n - 1; i >= 0; i--) {

            for (int canBuy = 0; canBuy <= 1; canBuy++) {

                for (int tCount = k-1; tCount >=0 ; tCount--) {

                    int profit = 0; // no buy sell so profit is zero initially

                    if (canBuy) {

                        int buy = -prices[i] + next[0][tCount];
                        int notBuy = 0 + next[1][tCount];

                        profit = max(buy, notBuy);

                    } else {

                        int sell = prices[i] +next[1][tCount+1];
                        int notSell = 0 + next[0][tCount];

                        profit = max(sell, notSell);
                    }

                   curr[canBuy][tCount] = profit;
                }
                next=curr;
            }
        }

        return next[1][0];
        
    }
};