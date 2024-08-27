class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int>temp;
        int n=nums.size();
       int ans=1;
       
       temp.push_back(nums[0]);
       
       for(int i=1;i<n;i++){
           
           if(nums[i]>temp.back()) {temp.push_back(nums[i]);
           ans++;}
           
           else{
           
           auto  it =lower_bound(temp.begin(),temp.end(),nums[i]);
           
           int idx=it-temp.begin();
           
           temp[idx]=nums[i];
           
       }
       }
       
       
       return ans;
        
    }
};