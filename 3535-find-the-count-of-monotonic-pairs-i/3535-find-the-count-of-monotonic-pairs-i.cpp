class Solution {
    
    int mod=(int)1e9+7;
    int solve(int i,int& n,vector<int>& nums,int prev1,int prev2,vector<vector<vector<int>>>&dp){

        if(i>=n) return 1;

        if(dp[i][prev1][prev2]!=-1) return dp[i][prev1][prev2];


        int  ans=0;
        for(int a=prev1;a<=nums[i];a++){

            int b=nums[i]-a;

            if( ( a>=prev1 && b<=prev2 ) ){

                ans+=solve(i+1,n,nums,a,b,dp);

                ans=ans%mod;

            }

           

             

        }

        return dp[i][prev1][prev2]=(ans)%mod;
    }
public:
    int countOfPairs(vector<int>& nums) {

        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(51,vector<int>(51,-1)));
        

        return  solve(0,n,nums,0,50,dp)%mod;


        
    }
};