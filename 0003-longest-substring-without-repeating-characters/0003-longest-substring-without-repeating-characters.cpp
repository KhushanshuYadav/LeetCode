class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;int right=0;
        int ans=0;
        unordered_map<char,int>m; //stores char and its index 
        while(right<n){
            if(  m.find(s[right])==m.end() ||   m[s[right]]<left){ 
                //either char is not map i.e not encountered so unique OR is in map but out of rangee i.e index <left so no part of substring
                m[s[right]]=right;
                ans=max(ans,right-left+1);
            }
            else{
                left=m[s[right]]+1;
                m[s[right]]=right;
            }
            right++;
        }

        return ans;

    }
};