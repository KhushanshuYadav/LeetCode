class Solution {

    void dfs(int v,vector<vector<int>>&graph,vector<int>&vis,int& g,unordered_map<int,int>&grid){
        vis[v]=1;
        grid[v]=g;

        for(auto& adj:graph[v]){
            if(!vis[adj]) dfs(adj,graph,vis,g,grid);
        }

    }

    vector<vector<int>>buildGraph(int& v, vector<vector<int>>& connections){

        vector<vector<int>>g(v+1);

        for(auto&c:connections){
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }

        return g;

        
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {


        auto graph=buildGraph(c,connections);

        unordered_map<int,int>grid;

        vector<int>vis(c+1,0);

        int g=0;

        for(int i=1;i<=c;i++){

            if(!vis[i]){

            
                dfs(i,graph,vis,g,grid);

                g++;



            }
        }

        unordered_map<int,set<int>>m;

        unordered_map<int,int>isOnline;
        

        vector<int>ans;

        for(int i=1;i<=c;i++) {
            isOnline[i]=1;
            m[grid[i]].insert(i);
        }

        for(auto&q:queries){

            int op=q[0];
            int pS=q[1];

            if(op==2) {
                isOnline[pS]=0;
                m[grid[pS]].erase(pS);
            }
            else{

                if(isOnline[pS]) ans.push_back(pS);

                else ans.push_back(*m[grid[pS]].begin());
            }


        }

        for(int&i:ans){
            if(i==0) i=-1;
        }

        return ans;

        
        
    }
};