class Solution {
private:

    //RETURNS THE MAX CASH WE CAN ROBB BY ROBBING TILL LAST HOUSE IF WE START ROBBING FROM i
    //so we are finding max value we can rob by starting from i
    //so same problem for each ith index


    int fun(int n,vector<int>& nums,vector<int>&dp){

        //if(n==0) return nums[n];

        if(n<0) return 0;                     //we cannot steal from out of bound index so cash stole from this i is zero

        if(dp[n]!=-1) return dp[n];

        int steal=nums[n]+fun(n-2,nums,dp);     //see we robbed i th house so now choice for i+2 house i.e return max if now start same problem from i+2
        int skip=fun(n-1,nums,dp);              //i th not robbed so i+1 can be robbed;

        return (dp[n]=max(steal,skip));



        
    
    }
public:
    int rob(vector<int>& nums) {

        int n=nums.size();
        int begin=0;
        

        //pick non-pick DP
        vector<int>dp(100,-1);

        return fun(n-1,nums,dp);

        



        

        
        
    }
};