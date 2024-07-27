class Solution {
private:
    void dijkstra(unordered_map<char, vector< pair<char,int> > >& graph, char& src,vector<vector<int>>&dist){
        
        

        priority_queue< pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>>pq; //dist,node

        pq.push({0,src});
        dist[src-'a'][src-'a']=0;


        while(!pq.empty()){
            char node=pq.top().second;
            int d=pq.top().first;
            pq.pop();


            for(auto p:graph[node]){
                int c=p.second;
                char adjNode=p.first;

                if(dist[src-'a'][adjNode-'a']>d+c){
                    dist[src-'a'][adjNode-'a']=d+c;
                    pq.push({dist[src-'a'][adjNode-'a'],adjNode});
                }
            }


        }

        return ;




    }
    void buildGraph( vector<char>& original, vector<char>& changed, vector<int>& cost, unordered_map<char, vector< pair<char,int> > >& graph){

        int edgeCount=original.size();

        for(int i=0;i<edgeCount;i++){

            char node=original[i];
            char adjNode=changed[i];
            int c=cost[i];

            graph[node].push_back( {adjNode,c} );

        }

        return ;

    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        unordered_map<char, vector< pair<char,int> > >graph;
        buildGraph(original,changed,cost,graph);

        vector<vector<int>>dist(26,vector<int>(26,INT_MAX));

        for(char& src:original){

            dijkstra(graph,src,dist);

        }

       

        int n=source.size();

        long long ans=0;

        for(int i=0;i<n;i++){

            

            if(source[i]!=target[i]){

                if(dist[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;

                else ans+=dist[source[i]-'a'][target[i]-'a'];



                




            }

        }

        

        return ans;



        
        
    }
};