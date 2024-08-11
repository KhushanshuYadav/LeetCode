class Solution {

private:
    //returns min sum to last row starting from cell i,j
    int solve(int i,int j,int& n,vector<vector<int>>& matrix,vector<vector<int>>& dp){

        if(i>=n || j>=n || j<0) return 10000000;

        if(i==n-1) return matrix[i][j];

        if(dp[i][j]!=-101) return dp[i][j];

        int downLeft=matrix[i][j]+solve(i+1,j-1,n,matrix,dp);
        int down=matrix[i][j]+solve(i+1,j,n,matrix,dp);
        int downRight=matrix[i][j]+solve(i+1,j+1,n,matrix,dp);

        return(dp[i][j]= min({downLeft,down,downRight}) );

    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        //TABULATION

        int n=matrix.size();
        int ans=INT_MAX;

        //stores min path sum to cell i,j from any cell in last row i.e last row to cell i,j min path
        vector<vector<int>>dp(n,vector<int>(n,-101));

        //fiiling dp table from last row to first row 

        for(int col=0;col<n;col++){
            dp[n-1][col]=matrix[n-1][col];
        }

        //we can arrive to i,j from the downLeft,down,downRight cells so take min of them

        for(int i=n-2;i>=0;i--){

            for(int j=0;j<n;j++){

                if(j==0){

                    int down=matrix[i][j]+dp[i+1][j];
                    int downRight=matrix[i][j]+dp[i+1][j+1];

                    dp[i][j]=min(down,downRight);



                }
                else if(j==n-1){

                    int down=matrix[i][j]+dp[i+1][j];
                    int downLeft=matrix[i][j]+dp[i+1][j-1];

                    dp[i][j]=min(down,downLeft);

                }

                else{

                    int down=matrix[i][j]+dp[i+1][j];
                    int downRight=matrix[i][j]+dp[i+1][j+1];
                    int downLeft=matrix[i][j]+dp[i+1][j-1];

                    dp[i][j]=min({down,downRight,downLeft});


                }
            }
        }

        for(int& i:dp[0]){
            ans=min(ans,i);
        }




        return ans;
        
    }
};