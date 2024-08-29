class Solution {

    int solve(int i,int j,vector<int>& temp,vector<vector<int>>& dp){

        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=INT_MIN;
        for(int k=i;k<=j;k++){

            //k th is the one which will be bursted at last in partition

            int current=temp[i - 1] * temp[k] * temp[j + 1];
            int left=solve(i,k-1,temp,dp);
            int right=solve(k+1,j,temp,dp);

            int total=current+left+right;

            ans=max(ans,total);
        }

        return dp[i][j]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {

        int n=nums.size();

        vector<int>temp;

        temp.push_back(1);

        
        for(int& i:nums){
            temp.push_back(i);

        }
        temp.push_back(1);

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        return solve(1,n,temp,dp);
        
    }
};