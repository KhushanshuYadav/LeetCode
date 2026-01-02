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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n=accounts.size();

        DSU dsu(n);

        unordered_map<string,int>m1;//stores mail, idx

        for(int i=0;i<n;i++){

            auto v1=accounts[i];

            for(int k1=1;k1<v1.size();k1++){

                string s1=v1[k1];

                if(m1.count(s1)) dsu.unionBySize(i,m1[s1]);

                else m1[s1]=i;

            }
        }

        unordered_map<int,set<string>>m;

        for(int i=0;i<n;i++){
            
            int repIdx=dsu.find(i);
            m[repIdx].insert( accounts[i].begin()+1,accounts[i].end());
        }

        vector<vector<string>>ans;

        for(auto&[u,s]:m){
            vector<string>v(s.begin(),s.end());
            //sort(v.begin(),v.end());
            v.insert(v.begin(),accounts[u][0]);
            ans.push_back(v);
        }

        return ans;
        
    }
};