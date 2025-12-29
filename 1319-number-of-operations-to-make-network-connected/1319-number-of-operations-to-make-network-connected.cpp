class Solution {

    class DSU{

        public:
        vector<int>rep;
        vector<int>rank;
        vector<int>size;

        

        DSU(int n){
            rep.resize(n);
            rank.resize(n,0);
            size.resize(n,1);

            for(int i=0;i<n;i++) rep[i]=i;
        }

        int find(int node){

            if(rep[node]==node) return node;

            return rep[node]=find(rep[node]);
        }

        void unionByRank(int u,int v){

            int repU=find(u);
            int repV=find(v);

            if(repU==repV) return;

            if(rank[repU]<rank[repV]) rep[repU]=repV;

            else if (rank[repU]>rank[repV]) rep[repV]=repU;

            else{
                rep[repV]=repU;
                rank[repU]++;
            }
        }

        void unionBySize(int u,int v){

            int repU=find(u);
            int repV=find(v);

            if(repU==repV) return;

            if(size[repU]<size[repV]){
                rep[repU]=repV;
                size[repV]+=size[repU];
            }
            else{
                rep[repV]=repU;
                size[repU]+=size[repV];
            }
        }

    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int cables=connections.size();
        if(cables<n-1) return -1; //as atleast n-1 edges should be there

        DSU dsu(n);

        for(int i=0;i<cables;i++){
            dsu.unionBySize(connections[i][0],connections[i][1]);
            //dsu.unionByRank(connections[i][0],connections[i][1]);
        }

        //for(int&i:dsu.rep) cout<<i<<" ";

        dsu.find(connections[cables-1][1]);

        for(int&i:dsu.rep) cout<<i<<" ";

        int ans=0;

        for(int i=0;i<n;i++) if(i==dsu.rep[i]) ans++;
        return ans-1;
    }
};