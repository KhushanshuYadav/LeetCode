class Solution {
public:
    int minDifference(vector<int>& nums) {

        int n =nums.size();
        sort(nums.begin(),nums.end());

        if(n<=4) return 0;

        //we use the fact that 
        //1. we need to either increase the min or decrease the max i.e replace 
        //2. we observe that doing this will change the max and min of arrays
        //3. we have at most 3 operations so we have only four combinations of either increase min or decreae max;
        //4. last 3 first 3 first 2 last 1 and vice versa

        return 
        (
            min
            (
               { nums[n-4]-nums[0], //decrease last 3 sp new max n-4 th and min is 0th
                nums[n-1]-nums[3], //increase first 3
                nums[n-2]-nums[2], //inc first 2 and dec last

                nums[n-3]-nums[1]  }//inc first and dec last 2

            )

        );


        
        
    }
};