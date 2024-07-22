class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        int n=names.size();
        //vector<string>ans;
        //map<int,string>m;
        priority_queue< pair<int,string> >pq;

        for(int i=0;i<n;i++){
            pq.push( {heights[i],names[i]} );
        }
        
        int i=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            names[i]=p.second;
            i++;
        }

       
        return names;
    }
};