class Solution {

    vector<vector<int>>buildGraph(int n){

        vector<vector<int>>graph(n);

        for(int node=0;node<n-1;node++){

            graph[node].push_back(node+1);

        }

        return graph;
    }

    void modifyGraph(vector<int>&edge,vector<vector<int>>&graph){

        int u=edge[0];
        int v=edge[1];

        graph[u].push_back(v);



    }

    int dijkstra(int n,vector<vector<int>>graph){

        vector<int>d(n,INT_MAX);

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;

        int src=0;

        pq.push({0,src});
        d[src]=0;

        while(!pq.empty()){

            int node=pq.top().second;
            int cost=pq.top().first;

            pq.pop();

            for(int& adjNode:graph[node]){

                int cost=1;

                if( d[adjNode]> (d[node]+cost) ){

                    d[adjNode]=d[node]+cost;
                    pq.push( { d[adjNode],adjNode });
                }
            }
        }

        return d[n-1];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        vector<int>ans;

        auto graph=buildGraph(n);

        for(auto& edge:queries){

            modifyGraph(edge,graph);

            int d=dijkstra(n,graph);

            ans.push_back(d);

            

            
        }

        return ans;
        
    }
};