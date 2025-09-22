class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int,int>m;

        int mx=0;

        for(int&i:nums){
            m[i]++;
            mx=max(mx,m[i]);
        }

        int ans=0;

        for(auto&[i,j]:m){
            if(j==mx) ans+=j;
        }

        return ans;
        
    }
};