class Solution {
    private:
    bool check(int src, vector<int>&set,vector<vector<int>>& graph){

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
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>set(n,-1);

        for(int i=0;i<n;i++){
            //by bfs
            if(set[i]==-1){
                if(check(i,set,graph)==false) return false;
            }
        }

        return true;
        

        
        
    }
};