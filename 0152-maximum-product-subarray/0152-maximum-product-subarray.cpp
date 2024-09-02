class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n =nums.size();

        int ans=*max_element(nums.begin(),nums.end());

        for(int i=0;i<n;i++){

            int temp=1;
            for(int j=i;j<n;j++){

                temp=temp*nums[j];

                ans=max(temp,ans);

                

            }
        }

        return ans;
        
    }
};