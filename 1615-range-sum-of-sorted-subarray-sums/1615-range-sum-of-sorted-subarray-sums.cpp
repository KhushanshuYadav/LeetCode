class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod=1000000007;

        vector<int>sums;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum=(sum+nums[j])%mod;
                sums.push_back(sum);
                
            }
        }

        sort(sums.begin(),sums.end());
        vector<int>prefix(sums.size(),0);

        prefix[0]=sums[0]%mod;
        for(int i=1;i<prefix.size();i++){
            prefix[i]=(prefix[i-1]+sums[i])%mod;
        }

        right=right-1;
        left=left-1;

        if(left==0){
            return (prefix[right]%mod);
        }
        
        return ( (prefix[right]-prefix[left-1])%mod );
        
        
    }
};