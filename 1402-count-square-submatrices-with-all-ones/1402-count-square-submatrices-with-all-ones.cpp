class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int rows=matrix.size();
        int cols=matrix[0].size();


        vector<vector<int>>dp(rows,vector<int>(cols));

        for(int col=0;col<cols;col++){
            dp[0][col]=matrix[0][col];
        }

        for(int row=0;row<rows;row++){
            dp[row][0]=matrix[row][0];
        }

        for(int i=1;i<rows;i++){

            for(int j=1;j<cols;j++){

                if(matrix[i][j]==1){

                    dp[i][j]=min( {dp[i-1][j-1],dp[i][j-1],dp[i-1][j]} )+1;  //+1 for itself
                    
                }
            }
        }

        int ans=0;

        for(auto &v:dp){

            for(auto& i:v){
                ans+=i;
            }

        }

        return ans;
        
    }
};