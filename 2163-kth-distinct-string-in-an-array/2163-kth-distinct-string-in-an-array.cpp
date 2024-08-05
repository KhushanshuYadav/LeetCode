class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {

        unordered_map<string, pair<int,int>>freq; //string,(index,freq);

        int n=arr.size();

        for(int i=0;i<n;i++){

            freq[arr[i]].first=i;
            freq[arr[i]].second++;


        }

        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;

        for(auto& [s,p]:freq){

            int f=p.second;

            if(f==1){
                pq.push({p.first,s});
            }

        }


        string ans="";

        

        while(k-- && !pq.empty()){

            auto p=pq.top();
            pq.pop();
            ans=p.second;



            

        }

        if(k>0 && pq.empty()) return "";
        return ans;
        
    }
};