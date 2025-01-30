class Solution {

    bool bipartite(int& src,vector<vector<int>>& graph, vector<int>&set){

        //vector<int>set(n,-1);

        queue<int>q;

        q.push(src);
        set[src]=0;

        while(!q.empty()){
            int node=q.front();
            int nodeSet=set[node];
            q.pop();

            for(int& adjNode:graph[node]){

                if(set[adjNode]==-1){
                    set[adjNode]=!nodeSet;
                    q.push(adjNode);
                }

                else if(set[adjNode]==nodeSet) return false;
            }
        }

        return true;

    }

    
    vector<vector<int>>buildGraph(vector<vector<int>>& edges,int n){

        vector<vector<int>>graph(n,vector<int>());
        
        for(auto& edge:edges){

            int u=edge[0];
            int v=edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

        }

        return graph;
    }

    int bfs(int& src, int n,vector<vector<int>>& graph){

        vector<int>vis(n,0);

        queue<int>q;

        q.push(src);
        vis[src]=1;

        int level=0;

        while(!q.empty()){

            int qS=q.size();

            while(qS--){

                int node=q.front();
                
                q.pop();

                for(int& adjNode:graph[node]){

                    if(!vis[adjNode]){
                        
                        q.push(adjNode);
                        vis[adjNode]=1;
                    }

                    
                }
                
            }

            level++;
            
        }

        return level;

    }

    int findMaxLevel(int& node,vector<vector<int>>graph,vector<int>&vis,vector<int>&levels){

        int l=levels[node];
        vis[node]=true;

        for(int& adjNode:graph[node]){
            if(!vis[adjNode]){
                l=max(l,findMaxLevel(adjNode,graph,vis,levels));
            }
        }

        return l;
        
        
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {

        auto graph=buildGraph(edges,n+1);

        vector<int>set(n+1,-1);
        for(int i=1;i<n+1;i++){

            if(set[i]==-1 && !bipartite(i,graph,set)) return -1;

        }


        vector<int>levels(n+1,0);
        for(int i=1;i<n+1;i++){
             levels[i]=bfs(i,n+1,graph);
        }

        vector<int>vis(n+1,0);
        int  maxGrpFromEachComp=0;
        for(int i=1;i<n+1;i++){

            if(!vis[i]) maxGrpFromEachComp+=findMaxLevel(i,graph,vis,levels);

        }

        return maxGrpFromEachComp;


        



       
        
    }
};