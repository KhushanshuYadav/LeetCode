class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        int n=arr.size();
        int ans=0;

        unordered_set<int>s(arr.begin(),arr.end());

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int nextTerm=arr[i]+arr[j];
                int prev=arr[j];
                int len=2;

                while(s.count(nextTerm)){
                    len++;
                    ans=max(ans,len);

                    int temp=nextTerm;
                    nextTerm+=prev;
                    prev=temp;
                }

            }
        }

        return ans;
        
    }
};