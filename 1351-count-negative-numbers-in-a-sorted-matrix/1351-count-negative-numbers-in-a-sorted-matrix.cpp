class Solution {

    int bS(int row,int low,int high,vector<vector<int>>& grid){

        int ans=-1;
        

        while(low<=high){

            int mid =low+(high-low)/2;

            if(grid[row][mid]<0){
                ans=mid;
                high=mid-1;
            }

            else low=mid+1;

        }

        return ans;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {

        int rows=grid.size();

        int cols=grid[0].size();

        int ans =0;

        for(int i=0;i<rows;i++){

            if(grid[i][0]<0) ans+=cols;

            else if(grid[i][cols-1]<0) ans+=(cols-bS(i,0,cols-1,grid));

        }

        return ans;
        
    }
};