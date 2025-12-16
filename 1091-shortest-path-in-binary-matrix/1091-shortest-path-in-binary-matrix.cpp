class Solution {

    int delR[8]={-1,-1,0,+1,+1,+1,0,-1};
    int delC[8]={0,+1,+1,+1,0,-1,-1,-1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n=grid.size();

        vector<vector<int>>vis(n,vector<int>(n,0));

        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;

        queue<vector<int>>q;

        q.push({0,0,1});
        vis[0][0]=1;

        //int count=1;

        while(!q.empty()){

            int r=q.front()[0];
            int c=q.front()[1];
            int k=q.front()[2];

            q.pop();

            bool flag=false;

            for(int i=0;i<8;i++){

                int newR=r+delR[i];
                int newC=c+delC[i];

                if( newR>=0 && newR<n && newC>=0 && newC<n && grid[newR][newC]==0 && !vis[newR][newC]){

                    q.push({newR,newC,k+1});
                    vis[newR][newC]=k+1;

                    flag=true;

                }

            }

            
        }

        if(vis[n-1][n-1]==0) return -1;

        return vis[n-1][n-1];
        
    }
};