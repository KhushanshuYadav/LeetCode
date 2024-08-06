class Solution {
private:
    vector<vector<pair<int,int>>>pSumMat(vector<vector<char>>& grid,int &rows,int &cols){

        vector<vector<pair<int,int>>>ans(rows, vector< pair<int,int> >(cols) );

        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){

                if(grid[row][col]=='X'){
                    ans[row][col].first=1;
                }

                if(grid[row][col]=='Y'){
                    ans[row][col].second=1;
                }

                //adding above
                if(row>0){
                    ans[row][col].first+=ans[row-1][col].first;
                    ans[row][col].second+=ans[row-1][col].second;
                }

                if(col>0){
                    ans[row][col].first+=ans[row][col-1].first;
                    ans[row][col].second+=ans[row][col-1].second;
                }

                if(row>0 && col>0){

                    ans[row][col].first-=ans[row-1][col-1].first;
                    ans[row][col].second-=ans[row-1][col-1].second;

                }

                

                
            }
        }

        return ans;

    }
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int rows=grid.size();
        int cols=grid[0].size();

        int ans=0;


        auto prefixSum=pSumMat( grid, rows, cols);

        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){

                if( (prefixSum[row][col].first>0) && (prefixSum[row][col].first==prefixSum[row][col].second) ) ans++;

            }
        }

     

        return ans;
        
        
    }
};