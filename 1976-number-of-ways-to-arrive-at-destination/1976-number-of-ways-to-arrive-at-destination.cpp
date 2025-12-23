class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        int mod=1e9+7;
        
        vector<vector<vector<int>>>graph(n,vector<vector<int>>());

        for(auto&f:roads) {
            graph[f[0]].push_back({f[1],f[2]});
            graph[f[1]].push_back({f[0],f[2]});
        }

        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;

        vector<long long>dis(n,LONG_MAX);

        pq.push({0,0});

        dis[0]=0;

        vector<int>noOfPaths(n,0);
        noOfPaths[0]=1;

        while(!pq.empty()){

            int cost=pq.top()[0];
            int node=pq.top()[1];

            //cout<<"node "<<node<<" cost "<<cost<<endl;
            
            pq.pop();

            if(cost>dis[node]) continue;

            //cout<<"in"<<endl;

        
           
            for(auto&v:graph[node]){

                int adj=v[0];
                int c=v[1];

                //cout<<"adj "<<adj<<" c "<<c<<endl;


                if(dis[adj]==dis[node]+c) {
                    
                    noOfPaths[adj]=(noOfPaths[adj]+noOfPaths[node])%mod;
                    //cout<<"equal "<<noOfPaths[adj]<<" "<<noOfPaths[node]<<" "<<noOfPaths[adj]<<endl;
                }

                else if( dis[adj]>dis[node]+c){
                    
                    dis[adj]=(dis[node]+c);
                    pq.push({dis[adj],adj});

                    noOfPaths[adj]=noOfPaths[node];

                    //cout<<"greater "<<noOfPaths[adj]<<" "<<noOfPaths[node]<<endl;
                    
                }
                
            }
        }

        return noOfPaths[n-1];
        
    }
};