class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int N=nums.size();

        int n=N/2;
        
        unordered_set<int>s;



        for(int i=0;i<N;i++){
            if(s.count(nums[i])) return nums[i];
            s.insert(nums[i]);
        }

        return -1;
        
    }
};