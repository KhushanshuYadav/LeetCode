class Solution {

private:
    //returns min sum to last row starting from cell i,j
    int solve(int i,int j,int& n,vector<vector<int>>& matrix,vector<vector<int>>& dp){

        if(i>=n || j>=n || j<0) return 10000000;

        if(i==n-1) return matrix[i][j];

        if(dp[i][j]!=-101) return dp[i][j];

        int downLeft=matrix[i][j]+solve(i+1,j-1,n,matrix,dp);
        int down=matrix[i][j]+solve(i+1,j,n,matrix,dp);
        int downRight=matrix[i][j]+solve(i+1,j+1,n,matrix,dp);

        return(dp[i][j]= min({downLeft,down,downRight}) );

    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int ans=INT_MAX;

        vector<vector<int>>dp(n,vector<int>(n,-101));

        for(int j=0;j<n;j++){
            int temp=solve(0,j,n,matrix,dp);
            ans=min(ans,temp);
        }




        return ans;
        
    }
};