class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        unordered_set<int>s;
        int n=nums.size();

        //int ans=0;

        for(int i=n-1;i>=0;i--){

            

            if(s.count(nums[i])){
                int count=i+1;
                int ans=ceil(count/3.0);
                return ans;
            }

            s.insert(nums[i]);

            
        }

        return 0;
        
    }
};