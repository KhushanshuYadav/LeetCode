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

       

        //return solve(rows-1,cols-1,grid,dp);

        //Tabulation;

        vector<int>prevRow(cols,-1);
        //each cell i,j stores min path sum from 0,0 to this cell reached by problem constraints

        //from 0,0 to 0,0 sum will be itself only
        prevRow[0]=grid[0][0]; 

        
        //on each cell in below loop we can reach from left cell only so cumalative sum of it 
        for(int col=1;col<cols;col++){
            prevRow[col]=grid[0][col]+prevRow[col-1];
        }

        //on each cell in below loop we can reach from top cell only so cumalative sum of it 
        /*for(int row=1;row<rows;row++){
            dp[row][0]=grid[row][0]+dp[row-1][0];
        }*/

        for(int i=1;i<rows;i++){

            prevRow[0]=grid[i][0]+prevRow[0];

            

            for(int j=1;j<cols;j++){

                //we require the min of sum of current state and left or above state to store in current cell

                int downSum=grid[i][j]+prevRow[j-1];
                int rightSum=grid[i][j]+prevRow[j];

                int ans=min(downSum,rightSum);

                prevRow[j]=ans;
                



                
            }

            
        }

        return prevRow[cols-1];

        
        
    }
};