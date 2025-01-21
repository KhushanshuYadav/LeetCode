class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        int n=grid[0].size();

        long long topRowSum=0;
        long long bottomRowSum=0;

        long long ans=LONG_LONG_MAX;

        for(int i=0;i<n;i++){
            topRowSum+=grid[0][i];
        }

        for(int i=0;i<n;i++){
            topRowSum-=grid[0][i];
            ans=min(ans,max(topRowSum,bottomRowSum));
            bottomRowSum+=grid[1][i];

           
        }

        return ans;
        
    }
};