class Solution {
    //return min path sum form cell i,j to cell rows-1,cols-1
    int solve(int i,int j,int& rows, int& cols,vector<vector<int>>& grid, vector<vector<int>>&dp){

        if(i>=rows || j>=cols) return 10000000;

        

        if(i==rows-1 && j==cols-1) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];
        

       

        
        int downSum=grid[i][j]+solve(i,j+1,rows,cols,grid,dp);
        int rightSum=grid[i][j]+solve(i+1,j,rows,cols,grid,dp);

        return (dp[i][j]=min(rightSum,downSum) );

    }
public:
    int minPathSum(vector<vector<int>>& grid) {

        int rows=grid.size();
        int cols=grid[0].size();

        vector<vector<int>>dp(rows,vector<int>(cols,-1));

        return solve(0,0,rows,cols,grid,dp);
        
    }
};