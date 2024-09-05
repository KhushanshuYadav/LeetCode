class Solution {

    void solve( int nodePlus1 ,int adjNodeMinus1, set<int>&s ){

        auto it1=s.lower_bound(nodePlus1);
        auto it2=s.upper_bound(adjNodeMinus1);

        s.erase(it1,it2);
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        vector<int>ans;
        set<int>s;

        for(int i=0;i<n;i++){
            s.insert(i);
        }

        for(auto& edge:queries){

            int node=edge[0];
            int adjNode=edge[1];

            solve(node+1,adjNode-1,s);

            ans.push_back(s.size()-1);
        }

        return ans;
        
    }
};