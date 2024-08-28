class Solution {

    vector<int>delRow={-1,0,+1,0};
    vector<int>delCol={0,+1,0,-1};

    void dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>& vis,bool& flag){

        vis[i][j]=1;

        if(grid2[i][j]==1 && grid1[i][j]!=1) flag=false;

        for(int k=0; k<4;k++){

            int newI=i+delRow[k];
            int newJ=j+delCol[k];

            if( (newI>=0 && newI<grid2.size() && newJ>=0 && newJ<grid2[0].size()) && !vis[newI][newJ] && grid2[newI][newJ]==1 ){
                dfs(newI,newJ,grid1,grid2,vis,flag);
            }
        }

        
    }


public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int rows=grid2.size();
        int cols=grid2[0].size();

        vector<vector<int>> vis(rows,vector<int>(cols,0));

        int ans=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){

                if( !vis[i][j] && grid2[i][j]==1 ){

                    bool flag=true;

                    dfs(i,j,grid1,grid2,vis,flag);

                    if(flag==true) ans++;
                }
            }
        }


        return ans;
        
    }
};