class Solution {
    private:
    int dfs(int node,int parent, vector<int>adj[],vector<bool>& hasApple){

        //WE BASICALLY CALL FOR EACH NODE AND WE CHECK IN ALL SUBTREE OF A NODE:
        //IF SUBTREE HAS APPLE WE GO THERE BY ADDING TIME
        int time=0;
        for(int& child:adj[node]){

            //cases:
            //child==parent so continue as dfs;
            //node's child's dfs says i have apple i.e child's subtree has apple so time from child >0
            //node's child says my subtree do not have apple BUT i have apple i.e hasApple[child]==true;

            if(child==parent) continue;

            int timeFromChild=dfs(child,node,adj,hasApple);

            if(timeFromChild>0 || hasApple[child]) time+=timeFromChild+2; //adding time from all childs for a parent;
            //+2 for node to child go and come;

            

        }
        return time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        //SINCE IT IS A TREE SO NO CYCLE SO NO VISITED ARRAY IS NEEDED;


        int ans=-1;
        vector<int>adj[n];
        for(auto &v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        

        return dfs(0,-1,adj,hasApple);
        
        
    }
};