class Solution {

    // tCount tells transaction count now a full transaction is when we buy and
    // sell stock so effectivaly transaction gets completed when we sell a stock
    // so inc then only see it as capacity of transaction

    int solve(int i, int canBuy, vector<int>& prices, int tCount,
              vector<vector<vector<int>>>& dp) {

        if (tCount >= 2)
            return 0;

        if (i >= prices.size())
            return 0;

        if (dp[i][canBuy][tCount] != -1)
            return dp[i][canBuy][tCount];

        int profit = 0; // no buy sell so profit is zero initially

        if (canBuy) {

            int buy = -prices[i] + solve(i + 1, 0, prices, tCount, dp);
            int notBuy = 0 + solve(i + 1, 1, prices, tCount, dp);

            profit = max(buy, notBuy);

        } else {

            int sell = prices[i] + solve(i + 1, 1, prices, tCount + 1, dp);
            int notSell = 0 + solve(i + 1, 0, prices, tCount, dp);

            profit = max(sell, notSell);
        }

        return dp[i][canBuy][tCount] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // Tabulation by including base cases i.e inc size
        //SPACE OPTIMIZATION

        vector<vector<int>> next(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

       

       
        next[0][2] = 0;
        next[1][2] = 0;

        curr[0][2] = 0;
        curr[1][2] = 0;
        

        for (int i = n - 1; i >= 0; i--) {

            for (int canBuy = 0; canBuy <= 1; canBuy++) {

                for (int tCount = 1; tCount >=0 ; tCount--) {

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