class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();

        int ans=0;

        unordered_map<int,int>m;//product,freq

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                int p=nums[i]*nums[j];

                if(m.count(p)){

                    int f=m[p];
                    ans=ans+(8*f);
                }

                m[p]++;

                
            }
        }

        
        return ans;
    }
};