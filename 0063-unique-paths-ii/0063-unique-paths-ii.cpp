class Solution {

private:
    //BELOW CODE is from m-1,n-1 to 0,0 i.e reverse i.e path to m,n from 0,0
    int solve(int m,int n,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){

        if(m<0 || n<0) return 0;


        if(obstacleGrid[m][n]==1) return 0;

       
        if(m==0 && n==0){
            return 1;
        }

        

        if(dp[m][n]!=-1) return dp[m][n];

        int down=solve(m-1,n,dp,obstacleGrid);
        int right=solve(m,n-1,dp,obstacleGrid);

        return(dp[m][n]= down + right);

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        
        //return solve(m-1,n-1,dp,obstacleGrid);

        //Tabulation 
        vector<int>prevRow(n,0);

        

        if(obstacleGrid[0][0]!=1) prevRow[0]=1;

        for(int col=1;col<n;col++){

            if(obstacleGrid[0][col]!=1 && prevRow[col-1]!=0 )  prevRow[col]=1;
           //only one way i.e right from 0,0

        }

        

    

        
        for(int i=1;i<m;i++){
            vector<int>currRow(n,0);
            if(obstacleGrid[i][0]!=1 && prevRow[0]!=0 )  currRow[0]=1;
            for(int j=1;j<n;j++){

                if(obstacleGrid[i][j]==1) currRow[j]=0;
                
                else{

                    int ans=0;
                    ans+=currRow[j-1];
                    ans+=prevRow[j];

                    currRow[j]=ans; 
                    
                }

              
            }

            prevRow=currRow;
        }

        return prevRow[n-1];

    }
};