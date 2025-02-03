class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n=nums.size();

        int ans=1;

        //stack<vector<int>>st;

        int ansI=1;
        int ansD=1;
        //st.push({nums[0],ansI,ansD});

        for(int i=1;i<n;i++){

            if( nums[i]>nums[i-1]){
                ansI++;
                ansD=1;
                //st.push({nums[i],ansI,ansD});
            }

            else if( nums[i]<nums[i-1] ){
                ansD++;
                ansI=1;
                //st.push({nums[i],ansI,ansD});
            }

            else{
                ansI=1;
                ansD=1;
                //st.push({nums[i],ansI,ansD});

            }

            ans=max({ans,ansI,ansD});
        }

        // while(!st.empty()) st.pop();

       
        // st.push({nums[0],ansD});

        // for(int i=1;i<n;i++){

            

        //     else{
        //         ansD=1;
        //         st.push({nums[i],ansD});

        //     }

        //     ans=max(ansD,ans);
        // }



        return ans;
        
    }
};