class Solution {

    vector<int>delRow={-1,0,+1,0};
    vector<int>delCol={0,+1,0,-1};

    bool isCellValid(int& i,int& j,vector<vector<int>>& vis,vector<vector<int>>& grid){
        
        return (  i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && !vis[i][j] && grid[i][j]>0 );
    }

    int dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid){
        vis[i][j]=1;
        int sum=grid[i][j];

        for(int k=0;k<4;k++){

            int newI=i+delRow[k];
            int newJ=j+delCol[k];

            if(isCellValid(newI,newJ,vis,grid)){
                sum+=dfs(newI,newJ,vis,grid);
            }
            
        }
        return sum;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows=grid.size();
        int cols=grid[0].size();

        vector<vector<int>>vis(rows,vector<int>(cols,0));

        int ans=INT_MIN;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){

              

                int sum=0;

                //understand that i we have reached x cell from y then we will y from x too as connected so a global vis
                if(grid[i][j]!=0 && !vis[i][j] ) sum=dfs(i,j,vis,grid);

                ans=max(sum,ans);

            }
        }

        return ans;
        
    }
};