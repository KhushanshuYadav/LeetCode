class Solution {
private:

    //RETURNS THE MAX CASH WE CAN ROBB BY ROBBING TILL LAST HOUSE IF WE START ROBBING FROM 0 to n
    //so we are finding max value we can rob by 0 from i
    //so same problem for each ith index
    //returns answer for subsequence starting from 0 to n index i.e max among all subsequence ending at index n in sub array 0 to n
    //REVERSE OF PREV RECURSION


    int fun(int n,vector<int>& nums,vector<int>&dp){

        //if(n==0) return nums[n];

        if(n<0) return 0;                     //we cannot steal from out of bound index so cash stole from this n is zero

        if(dp[n]!=-1) return dp[n];

        int steal=nums[n]+fun(n-2,nums,dp);     //see we robbed n th house so now choice for n-2 house i.e return max if now start same problem from n-2
        int skip=fun(n-1,nums,dp);              //i th not robbed so n-1 can be robbed;

        return (dp[n]=max(steal,skip));



        
    
    }
public:
    int rob(vector<int>& nums) {
        //pick non-pick DP

        int n=nums.size();
        int begin=0;
        vector<int>dp(n,-1); //stores max cash till i th house we can stole by pick not pick 
        
        //MEMOIZATION

        //return fun(n-1,nums,dp);

        
        //TABULATION
        dp[0]=nums[0];
       

        for(int i=1;i<n;i++){

            int v1=0;

            if(i-2<0)   v1=nums[i]+0;
            else   v1=nums[i]+dp[i-2];

            int v2=dp[i-1];

            
           


            dp[i]=max(v1,v2);


        }

        return dp[n-1];

       

       
        


       
       

        

        



        

        
        
    }
};