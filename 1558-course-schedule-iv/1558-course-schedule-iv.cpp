class Solution {
    vector<int>topoSort(int& v,vector<vector<int>>& graph){

        vector<int>inDegree(v,0);
        vector<int>ans;

        for(auto& v:graph){
            for(int& node:v){
                inDegree[node]++;
            }

        }

        queue<int>q;

        for(int i=0;i<v;i++){
            if(inDegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();

            ans.push_back(node);

            for(int& adjNode:graph[node]){
                inDegree[adjNode]--;
                if(inDegree[adjNode]==0) q.push(adjNode);
            }
        }

        return ans;
    }
    vector<vector<int>>buildGraph(int& v,vector<vector<int>>& edges){
        vector<vector<int>>graph(v,vector<int>());

        for(auto& edge:edges){

            int n1=edge[0];
            int n2=edge[1];

            graph[n1].push_back(n2);


        }

        return graph;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        int v=numCourses;
        vector<vector<bool>>isPre(v,vector<bool>(v,false));

        for(auto&edge:prerequisites){
            isPre[edge[0]][edge[1]]=true;
        }

        for(int k=0;k<v;k++){
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    isPre[i][j]=(isPre[i][j] || (isPre[i][k] && isPre[k][j]));
                }
            }
        }
        vector<bool>ans;
        for(auto& q:queries){
            ans.push_back(isPre[q[0]][q[1]]);
        }
        return ans;

        // vector<bool>ans(queries.size(),false);

        // if(prerequisites.size()==0) return ans;

        // auto graph=buildGraph(numCourses,prerequisites);

        // auto topo=topoSort(numCourses,graph);

        // for(int j=0;j<queries.size();j++){

        //     auto q=queries[j];

        //     int u=q[0];
        //     int v=q[1];
            
        //     int idx1=-1;
        //     for(int i=0;i<numCourses;i++){
        //         if(topo[i]==u) idx1=i;
        //     }

        //     int idx2=-1;
        //     for(int i=0;i<numCourses;i++){
        //         if(topo[i]==v) idx2=i;
        //     }

        //     if(idx1<idx2) ans[j]=true;

        // }

        // return ans;


        
    }
};