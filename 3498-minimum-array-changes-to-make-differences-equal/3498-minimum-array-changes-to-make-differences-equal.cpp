class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n =nums.size();

        vector<int>pairCount(k+1,0);
        unordered_map<int,int>m;//no op diff i.e current diff to its freq i.e pair count


        for(int i=0;i<n/2;i++){
            int e1=nums[i];
            int e2=nums[n-i-1];

            int diff=abs(e1-e2);
            m[diff]++;


            int minE=min(e1,e2);
            int maxE=max(e1,e2);

            int maxADiff=max( k-minE,maxE-0 );  //replace max with k ans k>=min and min with 0 respectively note range is from [0,k] for replace
            pairCount[maxADiff]++;


        }

        for(int i=k-1;i>=0;i--){
            pairCount[i]+=pairCount[i+1];
        }

        int ans=INT_MAX;
        for(auto& [diff,count]:m){
            int excludeExactDiff=pairCount[diff]-count;
            int tempAns=n/2-excludeExactDiff-count;

            ans=min(tempAns*2+excludeExactDiff,ans);
        }

        return ans;
    }
};