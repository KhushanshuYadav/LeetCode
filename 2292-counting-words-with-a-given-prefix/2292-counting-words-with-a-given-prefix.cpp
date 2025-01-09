class Solution {
    bool isPrefix(string& s, string& pref){
        if(pref.size()>s.size()) return false;

        for(int i=0;i<pref.size();i++){
            if(pref[i]!=s[i]) return false;
        }

        return true;
    }
public:
    int prefixCount(vector<string>& words, string pref) {

        int ans=0;
        for(string& s:words){
            if(isPrefix(s,pref)) ans++;
        }

        return ans;
        
    }
};