class Solution {

    bool isEqual(vector<int>& nums,vector<int>& temp){
        return (nums==temp);
    }

    void rotate(vector<int>& temp){

        int f=temp[0];
        for(int i=1;i<temp.size();i++){
            temp[i-1]=temp[i];
        }

        temp[temp.size()-1] =f;
    }
public:
    bool check(vector<int>& nums) {
        int n=nums.size();

       int count=0;

       for(int i=1;i<n;i++){

        if(nums[i]<nums[i-1]) count++;
        
       }
       if(nums[0]<nums[n-1]) count++;

       return count<=1;
    }
};