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

        

        //return solve(0, 0, n, triangle,dp);

        //SPACE  OPTIMIZATION

        //in table
        //each cell i,j stores min path sum to reach cell i,j from cell 0,0
        vector<int>prevRow;

        //filling base cases below

        //to each cell (i,j) we can arrive from UP (i-1,j) or UP-LEFT (i-1,j) cell  
        

       prevRow.push_back(triangle[0][0]);  //from 0,0 to 0,0 only sum possible is its own

        /*for(int row=1;row<n;row++){
            //at each of the cell of first col we can arrive from up only
            dp[row][0]=triangle[row][0]+dp[row-1][0];
        }*/

        for(int i=1;i<n;i++){
            vector<int>currRow(i+1);
            currRow[0]=prevRow[0]+triangle[i][0];

            for(int j=1;j<i+1;j++){

                if(j==i) currRow[j]=triangle[i][j]+prevRow[j-1] ; //we can only come from up-left cell

                else{
                    int upLeft=triangle[i][j]+prevRow[j-1];
                    int up=triangle[i][j]+prevRow[j];

                    currRow[j]=min(upLeft,up);
                }
            }

            prevRow=currRow;
        }

        int ans=INT_MAX;

        for(int &i:prevRow){
            ans=min(ans,i);
        }

        return ans;


    }
};