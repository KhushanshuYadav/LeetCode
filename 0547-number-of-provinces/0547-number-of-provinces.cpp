class Solution {

    void dfs(int& node,vector<vector<int>>& isConnected,vector<int>&vis){

        vis[node]=1;
        for(int adjNode=0;adjNode<isConnected.size();adjNode++){

            if(isConnected[node][adjNode] && !vis[adjNode]){
               dfs(adjNode,isConnected,vis);
                
            }
        }

        return;



    }

    void bfs(int& node,vector<vector<int>>& isConnected,vector<int>&vis){

        queue<int>q;

        q.push(node);
        vis[node]=1;

        while(!q.empty()){

            int node=q.front();
            q.pop();

            for(int adjNode=0;adjNode<isConnected.size();adjNode++){
                if(isConnected[node][adjNode] &&!vis[adjNode]){
                    q.push(adjNode);
                    vis[adjNode]=1;
                }
            }

        }

        return ;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n=isConnected.size();

        int ans=0;

        vector<int>vis(n,0);


        for(int i=0;i<n;i++){

            if(!vis[i]){
                //bfs(i,isConnected,vis);
                dfs(i,isConnected,vis);
                ans++;
            }
        }

        return ans;

        
        
    }
};