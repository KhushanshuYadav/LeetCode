class Solution {

    //return max profit from i th day by problem constraints

    //isPrevDaySell==1 means we have sold a stock on prev day
    int solve(int i,int canBuy,int isPrevDaySell,vector<int>& prices,vector<vector<vector<int>>>&dp){

        if(i>=prices.size()) return 0;


        if(dp[i][canBuy][isPrevDaySell]!=-1) return dp[i][canBuy][isPrevDaySell];


        int profit=0;
        if(canBuy){

            int buy=0;
            if(isPrevDaySell==0) buy=-prices[i]+solve(i+1,0,0,prices,dp);

            int notBuy=0+solve(i+1,1,0,prices,dp);

            profit=max(buy,notBuy);
        }

        else{

            int sell=prices[i]+solve(i+1,1,1,prices,dp);
            
            int notSell=0+solve(i+1,0,0,prices,dp);

            profit=max(sell,notSell);

        }

        return dp[i][canBuy][isPrevDaySell]=profit;

    }
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();

        vector<vector<vector<int>>>dp( n,vector<vector<int>>(2,vector<int>(2,-1)) );

        return solve(0,1,0,prices,dp);


        
        
    }
};