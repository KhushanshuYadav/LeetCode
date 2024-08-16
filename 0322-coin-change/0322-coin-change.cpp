class Solution {

    //return min no. of coins if we pick i th coin a last when we start picking /not picking from 0 th by question constraints

    // so when you have like can pick one again and again this approach is better 

    

    int solve(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){

        if(amount==0) return 0;  //no more coins are required 

        if(amount<0 || i<0) return INT_MAX;  //this combination makes sum > amount || no coins to pick and still sum>amount

        if(dp[i][amount]!=-1) return dp[i][amount];
        

        int take=solve(i,amount-coins[i],coins,dp);

        if(take!=INT_MAX) take+=1;

        int notTake=solve(i-1,amount,coins,dp);

        return(dp[i][amount]= min(take,notTake) );
    }
public:
    int coinChange(vector<int>& coins, int amount) {

        if(amount==0) return 0;
        
        for(int& c:coins){
            if (c==amount) return 1;
        }



        int n=coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int ans=solve(n-1,amount,coins,dp);

        if(ans==INT_MAX) return -1;

        return ans;




        
        
    }
};