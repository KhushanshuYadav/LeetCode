class Solution {
private:
    vector<int>pSE(vector<int>&arr,int n){

        stack<int>s;
        vector<int>ans;
        ans.push_back(-1);
        s.push(0);

        for(int i=1;i<n;i++){

            while(!s.empty() && arr[i]<=arr[s.top()]){
                s.pop();
            }

            int x=s.empty()?-1:s.top();
            ans.push_back(x);
            s.push(i);

        }

        return ans;
    }


    vector<int>nSE(vector<int>&arr,int n){
        
        stack<int>s;
        vector<int>ans;
        ans.push_back(n);
        s.push(n-1);

        for(int i=n-2;i>=0;i--){

            while(!s.empty() && arr[i]<arr[s.top()]){
                s.pop();
            }

            int x=s.empty()?n:s.top();
            ans.push_back(x);
            s.push(i);

        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n=arr.size();
        int mod=1e9+7;
        int sum=0;

        auto nextSIndex=nSE(arr,n);
        auto prevSIndex=pSE(arr,n);

        for(int i=0;i<n;i++){
            int leftSideCount=i-prevSIndex[i];
            int rightSideCount=nextSIndex[i]-i;

            long long int totalSubArrays=(leftSideCount*rightSideCount)%mod;
            long long int contribution=(totalSubArrays*arr[i])%mod;
            sum=(sum+contribution)%mod;
        }

        return sum;
        
    }
};