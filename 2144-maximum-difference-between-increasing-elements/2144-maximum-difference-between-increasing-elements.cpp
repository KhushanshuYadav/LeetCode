class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int mn=INT_MAX;
        int ans=INT_MIN;

        for(int& i:nums){
            mn=min(mn,i);
            ans=max(ans,i-mn);
        }

        return (ans==0?-1:ans);

        
    }
};