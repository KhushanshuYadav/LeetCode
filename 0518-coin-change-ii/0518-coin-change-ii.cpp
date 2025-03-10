class Solution {

    //returns count of combinations of coins if sum == amount passed 
    int solve(int i,int amount,vector<int>& coins,vector<vector<int>>&dp){


        if(amount<0) return 0;   //not a valid combination

        if(i<0){

            if(amount==0) return 1;  // a valid combination is found

            else return 0;           //no index to pick still cannot make amount we needed
        }

        if(dp[i][amount]!=-1) return dp[i][amount];

        int take=solve(i,amount-coins[i],coins,dp);   //pick and try to pick the same again till you get to know sub seq is valid or not

        int notTake=solve(i-1,amount,coins,dp);

        return ( dp[i][amount]= (take+notTake) );                   //understand not valid combinatiion will return zero so add can add them


    }
public:
    int change(int amount, vector<int>& coins) {

        int n =coins.size();

        //vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        //return solve(n-1,amount,coins,dp);

        //TABULATION

        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int row=0;row<n;row++){
            dp[row][0]=1;  // do not take any
        }

        for(int col=1;col<=amount;col++){

            if(col%coins[0]==0) dp[0][col] =1;

        }

        

        for(int i=1;i<n;i++){

            for(int j=1;j<=amount;j++){
                int  notTake=dp[i-1][j];

                int take=0;

                if(coins[i]<=j) take=dp[i][j-coins[i]];

                dp[i][j]=take+notTake;
            }
        }

        return dp[n-1][amount];


    }
};