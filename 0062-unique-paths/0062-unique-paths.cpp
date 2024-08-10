class Solution {
private:
    //returns total path from cell i,j to cell m-1,n-1 by following constraints of question

    //BELOW CODE is from m-1,n-1 to 0,0 i.e reverse i.e path to m,n from 0,0
    int solve(int m,int n,vector<vector<int>>& dp){

        if(m==0 && n==0){
            return 1;
        }

        if(m<0 || n<0) return 0;

        if(dp[m][n]!=-1) return dp[m][n];

        int down=solve(m-1,n,dp);
        int right=solve(m,n-1,dp);

        return(dp[m][n]= down + right);

    }
public:
    int uniquePaths(int m, int n) {

        if(m==1 && n==1) return 1;

        vector<vector<int>>dp(m,vector<int>(n,-1));
        //return solve(m-1,n-1,dp);
        //tabulation

        //filling base case
        dp[0][0]=1;

        for(int col=0;col<n;col++){
            dp[0][col]=1;

        }

        for(int row=0;row<m;row++){
            dp[row][0]=1;
            
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int ans=0;
                if(j-1>=0) ans+=dp[i][j-1];
                if(i-1>=0) ans+=dp[i-1][j];

                dp[i][j]=ans;
            }
        }

        return dp[m-1][n-1];
        

        

        
    }
};