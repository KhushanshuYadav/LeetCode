class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int ans=0;

        for(int row=0;row<rows/2;row++){

            for(int col=0;col<cols/2;col++){

                long  count=grid[row][col];
                count+=grid[row][cols-col-1];
                count+=grid[rows-row-1][col];
                count+=grid[rows-row-1][cols-col-1];

                ans+=min(count,4-count);

                

            }
        }

        if(rows%2==0 && cols%2==0) return ans;

        int oneZeroPCount=0;
        int oneOPCount=0;

        if(rows%2==1){

            int row=rows/2;
            for(int col=0;col<cols/2;col++){

                if((grid[row][col]==1) && (grid[row][cols-col-1]==1) )oneOPCount++;


                if(grid[row][col]!=grid[row][cols-col-1]){
                    ans++;
                    oneZeroPCount++;

                }

               


            }
        }


        
        if(cols%2==1){

            int col=cols/2;
            for(int row=0;row<rows/2;row++){

                if((grid[row][col]==1 )&& (grid[rows-row-1][col]==1)) oneOPCount++;


                if(grid[row][col]!=grid[rows-row-1][col]){
                    ans++;
                    oneZeroPCount++;

                }

               


            }
        }

        if((oneOPCount%2==1) && (oneZeroPCount==0)) ans+=2;
        if((rows%2==1) && (cols%2==1) && (grid[rows/2][cols/2]==1)) ans++;

        return ans;
    }
};