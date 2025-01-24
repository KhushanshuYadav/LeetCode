class Solution {
    bool detectedCycle(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathVis){
        vis[node]=1;
        pathVis[node]=1;

        //bool safe=true;
        for(int& adjNode: graph[node]){

            if( !vis[adjNode] ){

                if(detectedCycle(adjNode,graph,vis,pathVis)) return true;
            }


            else if( pathVis[adjNode] ){
                return true;
            }

            

        }

        pathVis[node]=0;

        return false;
    }

    vector<int> kahns(vector<vector<int>>& graph,int v){

        //int v=graph.size();

        vector<int>inDegree(v,0);

        for(int node=0;node<v;node++){

            for(int& adjNode:graph[node]){
                inDegree[adjNode]++;
            }
        }

        queue<int>q;
        for(int node=0;node<v;node++){

            if(inDegree[node]==0) q.push(node);

        }

        vector<int>ans(v,0);
        while(!q.empty()){

            int node=q.front();
            q.pop();

            ans[node]=1;

            for(int& adjNode:graph[node]){
                inDegree[adjNode]--;
                if(inDegree[adjNode]==0) q.push(adjNode);
            }

        }

        return ans;

    }

    vector<vector<int>>revGraphFun(vector<vector<int>>& graph,int v){
        vector<vector<int>>revGraph(v,vector<int>());

        for(int node=0;node<v;node++){

            for(int& adjNode:graph[node]){
                revGraph[adjNode].push_back(node);
            }

        }

        return revGraph;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {


        int v=graph.size();

        vector<int>vis(v,0);
        vector<int>pathVis(v,0);

        //vector<vector<int>>revGraph(v,vector<int>());

        auto revGraph=revGraphFun(graph,v);

        //auto ansTemp=kahns(revGraph,v);

        

        for(int i=0;i<v;i++) if(!vis[i]) detectedCycle(i,graph,vis,pathVis);
        vector<int>ans;
        //for(int i=0;i<v;i++) if(ansTemp[i]) ans.push_back(i);
        for(int i=0;i<v;i++) if(!pathVis[i]) ans.push_back(i);


        return ans;

        

        
    }
};