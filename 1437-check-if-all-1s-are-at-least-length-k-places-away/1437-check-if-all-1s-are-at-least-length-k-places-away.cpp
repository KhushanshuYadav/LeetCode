class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int count=0;
        int n=nums.size();

        int i=0;

        while(i<n && nums[i]==0){
            cout<<"i"<<endl;
            i++;
        }

        int I=i;

        for(;i<n;i++){

            if( i!=I && nums[i]==1 ){
                if(count<k) return false;
                count=0;
            }
            else if(nums[i]==0) count++;
        }


        return true;
        
    }
};