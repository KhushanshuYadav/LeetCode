class Solution {

    void dfs(int i,vector<int>&vis,vector<vector<int>>&graph){

        vis[i]=1;

        for(int&adj:graph[i]) if(!vis[adj]) dfs(adj,vis,graph);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int cables=connections.size();

        vector<vector<int>>graph(n,vector<int>());

        for(auto&c:connections){
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        

        if(cables<n-1) return -1; //as atleast n-1 edges should be there

        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]) {dfs(i,vis,graph); ans++;}
        }
        
        return ans-1;
    }
};