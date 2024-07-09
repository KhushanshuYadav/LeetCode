class Solution {
    private:
    int dfs(int node,int parent, vector<int>adj[],vector<bool>& hasApple){
        int time=0;
        for(int& child:adj[node]){

            if(child==parent) continue;

            int timeFromChild=dfs(child,node,adj,hasApple);

            if(timeFromChild>0 || hasApple[child]) time+=timeFromChild+2;

            

        }
         return time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        int ans=-1;
        vector<int>adj[n];
        for(auto &v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        //vector<int>vis(n,0);

        return dfs(0,-1,adj,hasApple);
        //return ans;
        
    }
};