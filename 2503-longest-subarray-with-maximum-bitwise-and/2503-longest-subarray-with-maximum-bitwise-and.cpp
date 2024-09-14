class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n=nums.size();

        int maxLen=0;
        int currLen=0;
        int maxAnd=*max_element(nums.begin(),nums.end());
        int maxElement=*max_element(nums.begin(),nums.end());

        for(int i=0;i<n;i++){

            if(nums[i]==maxElement){

                currLen++;
                maxLen=max(maxLen,currLen);

            }

            else{
                currLen=0;
            }
        }

        return maxLen;

        
        
    }
};