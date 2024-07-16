class Solution {
public:

    auto nextGreater(vector<int>&nums2){
        int n=nums2.size();
        vector<int>ans(n);

        stack<int>s;

        ans[n-1]=-1;

        s.push(nums2[n-1]);



        for(int i=n-2;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }

            int x = (s.empty())?-1:s.top();

            ans[i]=x;

            s.push(nums2[i]);
        }


        return ans;





        
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        auto nextG=nextGreater(nums2);

        unordered_map<int,int>m;  //nums2,their next greter

        for(int i=0;i<nextG.size();i++){
            m[nums2[i]]=nextG[i];
        }
        

        vector<int>ans;

        for(int i:nums1){
            ans.push_back( m[i] );
        }

        return ans;


    }
};