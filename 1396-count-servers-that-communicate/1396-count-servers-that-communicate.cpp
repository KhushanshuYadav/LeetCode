class Solution {

    bool inRow(int& row,int& col,vector<vector<int>>& grid){

        int cols=grid[0].size();

        for(int i=0;i<cols;i++){
            if( i!=col && grid[row][i] ) return true;
        }

        return false;

    }

    bool inCol(int& row,int& col,vector<vector<int>>& grid){

        int rows=grid.size();

        for(int i=0;i<rows;i++){
            if(i!=row && grid[i][col]) return true;
        }

        return false;

    }
public:
    int countServers(vector<vector<int>>& grid) {


        int rows=grid.size();
        int cols=grid[0].size();

        int ans=0;

        for(int i=0;i<rows;i++){

            for(int j=0;j<cols;j++){


                if( (grid[i][j]==1) && (inRow(i,j,grid) || inCol(i,j,grid)) ) ans++;
            }
        }

        return ans;
        
    }
};