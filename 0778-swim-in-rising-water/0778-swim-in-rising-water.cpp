class Solution {
    int delR[4]={-1,0,+1,0};
    int delC[4]={0,+1,0,-1};
    class DSU{

        public:
        vector<int>rep;
        vector<int>rank;
        vector<int>size;

        

        DSU(int n){
            rep.resize(n);
            rank.resize(n,0);
            size.resize(n,1);

            for(int i=0;i<n;i++) rep[i]=i;
        }

        int find(int node){

            if(rep[node]==node) return node;

            return rep[node]=find(rep[node]);
        }

        void unionByRank(int u,int v){

            int repU=find(u);
            int repV=find(v);

            if(repU==repV) return;

            if(rank[repU]<rank[repV]) rep[repU]=repV;

            else if (rank[repU]>rank[repV]) rep[repV]=repU;

            else{
                rep[repV]=repU;
                rank[repU]++;
            }
        }

        void unionBySize(int u,int v){

            int repU=find(u);
            int repV=find(v);

            if(repU==repV) return;

            if(size[repU]<size[repV]){
                rep[repU]=repV;
                size[repV]+=size[repU];
            }
            else{
                rep[repV]=repU;
                size[repU]+=size[repV];
            }
        }

    };

    bool bfs(vector<vector<int>>& grid,int& t){

        if(grid[0][0]>t) return false;
        int n=grid.size();

        vector<vector<int>>vis(n,vector<int>(n,0));

        queue<vector<int>>q;

        q.push({0,0});
        vis[0][0]=1;

        int ans=INT_MIN;

        while(!q.empty()){

            int r=q.front()[0];
            int c=q.front()[1];

            // cout<<grid[r][c]<<endl;

            // ans=max(ans,grid[r][c]);

            q.pop();

            if(r==n-1 && c==n-1) return true;

            // int mn=INT_MAX;
            // int R=-1;
            // int C=-1;


            for(int i=0;i<4;i++){

                int nR=r+delR[i];
                int nC=c+delC[i];

                if(nR>=0 && nR<n && nC>=0 && nC<n && !vis[nR][nC] && grid[nR][nC]<=t){

                    q.push({nR,nC});
                    vis[nR][nC]=1;

                    
                }
            }
            // if (R == -1 || C == -1) continue;   

          

        }

        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {

        int n=grid.size();

        int mn=INT_MAX;
        int mx=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                mn=min(mn,grid[i][j]);
                mx=max(mx,grid[i][j]);

            }
        }

        int ans=INT_MIN;
        
        while(mn<=mx){

            int mid= mn+(mx-mn)/2;

            if(bfs(grid,mid)) {
                ans=mid;
                mx=mid-1;
            }

            else mn=mid+1;


        }

        return ans;        
    }
};