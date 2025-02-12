class Solution {

    int digitSum(int n){
        int ans=0;
        while(n){
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }
public:
    int maximumSum(vector<int>& nums) {

       int n=nums.size();

       vector<pair<int,int>>v;

       for(int& i:nums){
        int dSum=digitSum(i);
        v.push_back({dSum,i});
       }

       sort(v.begin(),v.end());

       int ans=-1;

       for(int i=1;i<n;i++){

        int prevSum=v[i-1].first;
        int sum=v[i].first;

        if(prevSum==sum){
            //means they belong to same group

            ans=max(ans,v[i-1].second+v[i].second);

        }

       }


       return ans;
        
    }
};