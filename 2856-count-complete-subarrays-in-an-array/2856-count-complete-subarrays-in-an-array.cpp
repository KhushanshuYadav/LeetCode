class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0;

        unordered_set<int>s(nums.begin(),nums.end());

        for(int i=0;i<n;i++){

            unordered_set<int>temp;

            for(int j=i;j<n;j++){ 
                
                temp.insert(nums[j]);
                if(temp.size()==s.size()) ans++;
            }

           

        }

        
        return ans;
    }

    
};