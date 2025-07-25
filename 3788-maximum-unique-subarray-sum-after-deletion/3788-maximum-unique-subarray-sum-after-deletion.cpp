class Solution {
public:
    int maxSum(vector<int>& nums) {

        

        int ans=INT_MIN;

        int n=nums.size();

        if(n==1) return nums[0];

        int sum=0;

        int maxE=INT_MIN;

        //sort(nums.begin(),nums.end());

        unordered_set<int>s;

        for(int& i:nums){
            if (!s.count(i) && i>0) {sum+=(i);s.insert(i);}
            ans=max(ans,sum);
            maxE=max(maxE,i);
        }

        return maxE<=0?maxE:ans;
        
    }
};