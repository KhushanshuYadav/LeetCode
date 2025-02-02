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

        int pivot=-1;

        int count=0;

        

        for(int i=1;i<n;i++){

            if(nums[i]<nums[i-1]) {pivot=i;count++;}

            

        }

        cout<<pivot<<" ";
        cout<<count;

        if(count>1) return false;
        if(pivot==-1) return true;


        
        for(int i=pivot;i<n-1;i++){

            if(nums[i]>nums[i+1]) return false;
        }

        if(nums[n-1]>nums[0]) return false;

        

        return true;
    }
};