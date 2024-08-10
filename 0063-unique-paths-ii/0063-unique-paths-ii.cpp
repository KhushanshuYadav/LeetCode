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
        vector<vector<int>>dp(m,vector<int>(n,0));

        

        if(obstacleGrid[0][0]!=1) dp[0][0]=1;

        for(int col=1;col<n;col++){

            if(obstacleGrid[0][col]!=1 && dp[0][col-1]!=0 )  dp[0][col]=1;
           //only one way i.e right from 0,0

        }

        for(int row=1;row<m;row++){

            if(obstacleGrid[row][0]!=1 && dp[row-1][0]!=0 ) dp[row][0]=1;
            //one way i.e down from 0,0
            
        }

    

        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){

                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                
                else{

                    int ans=0;
                    ans+=dp[i][j-1];
                    ans+=dp[i-1][j];

                    dp[i][j]=ans; 
                    
                }

              
            }
        }

        return dp[m-1][n-1];

    }
};