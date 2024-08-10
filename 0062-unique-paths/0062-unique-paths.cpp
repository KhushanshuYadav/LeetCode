class Solution {
private:
    //returns total path from cell i,j to cell m-1,n-1 by following constraints of question

    //BELOW CODE is from m-1,n-1 to 0,0 i.e reverse
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
        return solve(m-1,n-1,dp);
        //tabulation

        
    }
};