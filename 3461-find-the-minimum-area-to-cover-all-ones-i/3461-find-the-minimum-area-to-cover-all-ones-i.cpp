class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int rows=grid.size();
        int cols=grid[0].size();

        int rS=INT_MAX;
        int rE=INT_MIN;

        int cS=INT_MAX;
        int cE=INT_MIN;

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){

                if(grid[r][c]==1){

                    rS=min(rS,r);
                    rE=max(rE,r);

                    cS=min(cS,c);
                    cE=max(cE,c);

                }
            }
        }        

        return ((cE-cS+1)*(rE-rS+1));
    }
};