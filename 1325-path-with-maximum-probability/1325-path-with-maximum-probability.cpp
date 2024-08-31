class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        int edgeC=edges.size();

        vector<vector< pair<int,double> >>graph(n);

        for(int i=0;i<edgeC;i++){

            auto e=edges[i];

            int u=e[0];
            int v=e[1];
            double p=succProb[i];
        
            graph[u].push_back({v,p});
            graph[v].push_back({u,p});


        }

        priority_queue< pair<double,int> >pq;

        vector<double>prob(n,0.0);

        
        prob[start_node]=1;
        pq.push( {prob[start_node],start_node} );
       

        while(!pq.empty()){

            int node=pq.top().second;
            double p=pq.top().first;

            pq.pop();

            for(auto& v:graph[node]){

                int adjNode=v.first;
                double P=v.second;

                if( (p*P)> prob[adjNode]){

                    prob[adjNode]=p*P;

                    pq.push( { prob[adjNode],adjNode} );
                }

            }


        }


        return prob[end_node];


        
    }
};