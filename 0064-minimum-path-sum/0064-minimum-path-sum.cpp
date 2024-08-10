class Solution {
    //return min path sum from cell 0,0 to cell i,j i.e reverse of first to last
    int solve(int i,int j,vector<vector<int>>& grid, vector<vector<int>>&dp){

        if(i<0|| j<0) return 10000000;

        

        if(i==0 && j==0) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];
        

       

        
        int downSum=grid[i][j]+solve(i,j-1,grid,dp);
        int rightSum=grid[i][j]+solve(i-1,j,grid,dp);

        return (dp[i][j]=min(rightSum,downSum) );

    }
public:
    int minPathSum(vector<vector<int>>& grid) {

        int rows=grid.size();
        int cols=grid[0].size();

        vector<vector<int>>dp(rows,vector<int>(cols,-1));

        return solve(rows-1,cols-1,grid,dp);
        
    }
};