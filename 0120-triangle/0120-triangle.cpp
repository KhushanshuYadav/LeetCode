class Solution {
private:
    //gives min path sum from cell i,j to ending row
    int solve(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        //if (i >= n) return 10000000;

        if (i == n - 1)
            return triangle[i][j];  //understand ending row is our destination no matter the j as j inc lineraly so no check for it

        if(dp[i][j]!=-1) return dp[i][j];    

        int down = triangle[i][j] + solve(i + 1, j, n, triangle,dp);
        int downRight = triangle[i][j] + solve(i + 1, j + 1, n, triangle,dp);

        return(dp[i][j]= min(down, downRight) );
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        return solve(0, 0, n, triangle,dp);
    }
};