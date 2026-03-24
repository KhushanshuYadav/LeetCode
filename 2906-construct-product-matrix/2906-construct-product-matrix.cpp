class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        int rows=grid.size();
        int cols=grid[0].size();

        int mod=12345;

        vector<vector<int>>ans(rows,vector<int>(cols,1));

       

        ans[0][0]=1;
        long long int product=grid[0][0];
        for(int i=0;i<rows;i++){

            for(int j=(i==0?1:0);j<cols;j++){

                product%=mod;
                ans[i][j]=product;
                product=(product*grid[i][j])%mod;
               
            }

        } 

        product=grid[rows-1][cols-1];
        for(int i=rows-1;i>=0;i--){
            for(int j=(i==rows-1?cols-2:cols-1);j>=0;j--){
                product%=mod;
                ans[i][j]=(product*ans[i][j])%mod;
                product=(product*grid[i][j])%mod;
            }
        }

        

        for(int i=0;i<rows;i++){

            for(int j=0;j<cols;j++){

                cout<<ans[i][j]<<" ";

            }

            cout<<endl;
        }

        return ans;
        
    }
};