class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_set<string>st;
        vector<string>ans;

        ans.push_back(words[0]);

        int n=words.size();

        int prev=0;

        for(int i=1;i<n;i++){

            string s=words[i];
            string org=words[i];
            string temp=ans.back();

            sort(s.begin(),s.end());
            sort(temp.begin(),temp.end());

            if(s!=temp) ans.push_back(org);

        }  

        

        return ans;
    }
};