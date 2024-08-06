class Solution {
private:
    int fun(int begin,int& n, vector<int>&dp){
        if(begin>n) return 0;

        if(begin==n){
            
            if(dp[begin]!=-1) return dp[begin];
            else return dp[begin]=1;
            
        }

       

        if(dp[begin]!=-1) return dp[begin];
        
        else {
            int ones=fun(begin+1,n,dp);
            int twos=fun(begin+2,n,dp);
            return ( dp[begin]=ones+twos);
        }


        
        
       
      


        
    }    
public:
    int climbStairs(int n) {

        int begin=0;
        int ans=0;
        vector<int>dp(n+1,-1);
        return fun(begin,n,dp);

        
        
    }
};