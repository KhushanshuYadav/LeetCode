class Solution {


    int solve(int i,int canBuy,vector<int>& prices, int& fee,vector<vector<int>>& dp){

        if(i>=prices.size()) return 0;





        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        int profit=0;

        if(canBuy){

            int buy=-prices[i]+solve(i+1,0,prices,fee,dp);
            int notBuy=0+solve(i+1,1,prices,fee,dp);

            profit=max(buy,notBuy);

        }


        else{

            int sell=prices[i]+solve(i+1,1,prices,fee,dp)-fee;
            int notSell=0+solve(i+1,0,prices,fee,dp);

            profit=max(sell,notSell);

        }

        return dp[i][canBuy]= profit;

    }

public:
    int maxProfit(vector<int>& prices, int fee) {

        int n =prices.size();

        vector<vector<int>>dp(n,vector<int>(2,-1));

        return solve(0,1,prices,fee,dp);
        
    }
};