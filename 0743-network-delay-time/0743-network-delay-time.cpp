class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<vector<int>>>graph(n+1,vector<vector<int>>());
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>>  >pq;

        vector<int>d(n+1,INT_MAX);

        int ans=INT_MIN;

        int count=0;

        for(auto&e:times) graph[e[0]].push_back({e[1],e[2]});

        pq.push({0,k});
        d[k]=0;

        while(!pq.empty()){

            int node=pq.top()[1];
            int cost=pq.top()[0];

            //cout<<"node "<<node<<" cost "<<cost<<endl;
            
            


            //cout<<"count "<<count<<endl; 

            //cout<<"ans "<<ans<<endl;
            pq.pop();

            if(cost>d[node]) continue; 

            ans=max(ans,cost);
            count++;

            for(auto&v:graph[node]){
                int adj=v[0];
                int time=v[1];

                //cout<<"adj "<<adj<<" time "<<time<<" d[adj] "<<d[adj]<<endl;

                if(d[node]+time<d[adj]){

                    //cout<<"in loop"<<endl;
                    d[adj]=d[node]+time;
                    //cout<<"adj "<<adj<<" time "<<time<<" d[adj] "<<d[adj]<<endl;
                    pq.push({d[adj],adj});
                }
            }


        }

        //for(int i=1;i<n+1;i++)  if(d[i]==INT_MAX) return -1; // i dont want this additional loop

        return ans==0?-1:count<n?-1:ans;

        
    }
};