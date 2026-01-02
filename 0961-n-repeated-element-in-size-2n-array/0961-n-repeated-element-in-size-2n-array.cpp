class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int N=nums.size();

        int n=N/2;
        
        //unordered_set<int>s;

        if(n==2 && nums[0]==nums[N-1]) return nums[0];



        for(int i=0;i<N;i++){

            if( (nums[i]==nums[i+1] || nums[i]==nums[i+2]) ) return nums[i];
           
        }

        return -1;
        
    }
};