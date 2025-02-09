class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        long long n=nums.size();
        long long ans=(n*(n-1))/2;

        long long count=0;

        unordered_map<int,int>m;  //diff,freq

        for(int i=0;i<n;i++){

            int diff=i-nums[i];

            if(m.count(diff)){
                count+=m[diff];
            }

            m[diff]++;

        }

        

        ans-=count;
        return ans;
        
    }
};