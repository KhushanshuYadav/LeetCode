class Solution {

    int r,c;

    int MOD=1e9+7;

    int solve(int i,int j,int sum,vector<vector<int>>& grid,int& k,vector<vector<vector<int>>>&dp){

        if(i>=r|| j>=c) return 0;

        sum+=grid[i][j];
        sum%=k;
        
        if(i>=r-1 && j>=c-1){
            if(sum%k==0) return 1;
            return 0;
        }

        if(dp[i][j][sum]!=-1) return dp[i][j][sum];

        

        int down=solve(i+1,j,sum,grid,k,dp)%MOD;
        int right=solve(i,j+1,sum,grid,k,dp)%MOD;

        return dp[i][j][sum]=(down+right)%MOD;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        r=grid.size();
        c=grid[0].size();

        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(k+1,-1)));

        return solve(0,0,0,grid,k,dp)%MOD;


        
    }
};