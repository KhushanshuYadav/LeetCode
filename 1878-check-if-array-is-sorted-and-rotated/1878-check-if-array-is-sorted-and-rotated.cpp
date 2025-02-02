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

        vector<int>temp=nums;

        sort(temp.begin(),temp.end());

        if(isEqual(nums,temp)) return true;

        for(int i=0;i<n;i++){

            rotate(temp);

            if(isEqual(temp,nums)) return true;
        }

        return false;
    }
};