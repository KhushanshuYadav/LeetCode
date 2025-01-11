class Solution {
public:
    bool canConstruct(string s, int k) {

        if(k>s.size()) return false;

        unordered_map<char,int>m;

        for(char& c:s){
            m[c]++;
        }

        int oddCount=0;
        for(auto& i:m){

            if((i.second%2)!=0) oddCount++;
        }

        return (oddCount<=k);        
        
    }
};