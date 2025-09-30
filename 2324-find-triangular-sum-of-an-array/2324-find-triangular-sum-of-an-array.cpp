class Solution {
public:
    int triangularSum(vector<int>& nums) {

        int n=nums.size();
        vector<int>v=nums;

        while(n>1){
            vector<int>temp;
            for(int i=0;i<n-1;i++){
                temp.push_back((v[i]+v[i+1])%10);
            }
            n=temp.size();
            v=temp;

            if(n==1) return temp[0];
        }

        return v[0];
        
    }
};