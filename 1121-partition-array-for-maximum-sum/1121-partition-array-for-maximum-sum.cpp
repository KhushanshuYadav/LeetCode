class Solution {
    int solve(int i, int& n,vector<int>& arr, int& k,vector<int>& dp){

        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];

        

        int length=0;
        int maxE=INT_MIN;
        int ans=INT_MIN;
        for(int cutIndex=i; cutIndex<min(i+k,n) ; cutIndex++ ){
            length++;
            maxE=max(maxE,arr[cutIndex]);

            int leftPortionSum=maxE*length;
            int rightPortionSum=solve(cutIndex+1,n,arr,k,dp);

            ans=max(ans,leftPortionSum+rightPortionSum);
        }

        return dp[i]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n=arr.size();
        vector<int>dp(n,-1);

        return solve(0,n,arr,k,dp);

        
    }
};