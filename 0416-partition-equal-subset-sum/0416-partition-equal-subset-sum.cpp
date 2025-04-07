class Solution {
    bool solve(int i,vector<int>&nums,int sum,int& total,vector<vector<int>>&dp){

        if(i>=nums.size()){

            int diff=total-sum;

            if(diff==sum) return true;

            return false;

            
        }

        if(dp[i][sum]!=-1) return dp[i][sum];


        bool take=solve(i+1,nums,sum+nums[i],total,dp);

        bool notTake=solve(i+1,nums,sum,total,dp);

        return ( dp[i][sum]=(take||notTake) );
    }
public:
    bool canPartition(vector<int>& nums) {

        int total=accumulate(nums.begin(),nums.end(),0);

        vector<vector<int>>dp(nums.size(),vector<int>(total+1,-1));

        return solve(0,nums,0,total,dp);
        
    }
};