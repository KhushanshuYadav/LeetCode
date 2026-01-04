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
    int swimInWater(vector<vector<int>>& heights) {

        int rows=heights.size();
        int cols=heights[0].size();

        

        vector<vector<int>>dis(rows,vector<int>(cols,INT_MAX));//store min across all paths

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({heights[0][0],0,0});
        dis[0][0]=heights[0][0];

        while(!pq.empty()){

            int C=pq.top()[0]; //cost till r,c from 0,0
            int r=pq.top()[1];
            int c=pq.top()[2];

            pq.pop();

            if(r==rows-1 && c==cols-1) return C;

            if(C>dis[r][c]) continue;      //C can be == or > not < to avoid stale entry

            for(int k=0;k<4;k++){

                int newR=r+delR[k];
                int newC=c+delC[k];

                if(newR>=0 && newR<rows && newC>=0 && newC<cols){

                    int cost = heights[newR][newC]; //cost from r,c to newR,newC

                    int maxPathCost=max(cost,C);  //the max cost of curr path either of r,c or newR,newC as both in same path

                    if(dis[newR][newC]>maxPathCost){
                        dis[newR][newC]=maxPathCost;
                        pq.push({dis[newR][newC],newR,newC});
                    }


                }

            }
        }


        return 0;   
    }
};