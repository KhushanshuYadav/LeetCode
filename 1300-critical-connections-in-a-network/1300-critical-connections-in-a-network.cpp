class Solution {
private:
    unordered_map<int,vector<int>>buildGraph(vector<vector<int>>& connections){

       unordered_map<int,vector<int>>ans;

       for(auto& edge:connections){

        int u=edge[0];
        int v=edge[1];

        ans[u].push_back(v);
        ans[v].push_back(u);

        
       }





        return ans;
    }

    void findBridges(int node,int parent, unordered_map<int,vector<int>>& graph, vector<int>& vis,vector<int>& inTime,vector<int>& lowestTime,int& time,vector<vector<int>>& ans){

        vis[node]=1;
        inTime[node]=time;
        lowestTime[node]=time;

        time++;

        for( int& adjNode:graph[node] ){
            if(adjNode==parent) continue;

            if(!vis[adjNode]){

                findBridges(adjNode,node,graph,vis,inTime,lowestTime,time,ans);
                lowestTime[node]=min(lowestTime[node],lowestTime[adjNode]);

                if(lowestTime[adjNode]>inTime[node]) ans.push_back({node,adjNode});
                


            }

            else{

                lowestTime[node]=min(lowestTime[node],lowestTime[adjNode]);

            }
        }

        return;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>>ans;

        auto graph=buildGraph( connections);

        //int n=graph.size();

        vector<int>vis(n,0);
        vector<int>inTime(n,0);
        vector<int>lowestTime(n,0);

        

        int time=1;

        findBridges(1,-1,graph,vis,inTime,lowestTime,time,ans);

        return ans;
        
    }
};