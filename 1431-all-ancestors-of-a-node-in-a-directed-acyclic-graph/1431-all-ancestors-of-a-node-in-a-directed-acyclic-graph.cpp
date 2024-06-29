class Solution {

    //DO IT BY TOPOSORT

    private:
    void dfs(int node,int parent,vector<int>adj[],vector<int>&vis,vector<vector<int>>&ans){
        vis[node]=1;
        
        for(int &i:adj[node]){
            
            if(!vis[i]) {
                ans[i].push_back(parent);
                dfs(i,parent,adj,vis,ans); }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges){
       

        vector<int>adj[n];
       

        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
        }

        vector<vector<int>>ans(n);


        //we are making each node a parent and finding dfs and pushing parent in all nodes appearing in dfs call
        //O(n^2)

        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(i,i,adj,vis,ans);
            //ans[i].clear();
        }


        return ans;

        

    }
};