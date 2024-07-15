class Solution {
public:
    int fun(int i,int j,int m,int n,vector<vector<int>>&dp){
       

        if(i==m-1 && j==n-1) return 1;

        if(i>=m || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        else return  dp[i][j]= fun(i+1,j,m,n,dp)+fun(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {

        int N=n+m-2;
        int r=m-1;
        double res=1;

        for(int i=1;i<=r;i++){
            res=res*(N-r+i)/i;
        }

        return (int)res;

        
        
    }
};