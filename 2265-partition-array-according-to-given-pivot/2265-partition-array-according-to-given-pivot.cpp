class Solution {

public:
    vector<int> pivotArray(vector<int>& arr, int pivot) {
        int n = arr.size();

        vector<int>ans;
        //vector<int>vis(n,0);

        for(int i=0;i<n;i++){

            if(arr[i]<pivot ) {
                ans.push_back(arr[i]);
                //vis[i]=1;
            }

        }

        for(int i=0;i<n;i++){

            if(arr[i]==pivot  ) {
                ans.push_back(arr[i]);
                //vis[i]=1;
            }

        }

        for(int i=0;i<n;i++){

            if(arr[i]>pivot ) {
                ans.push_back(arr[i]);
                //vis[i]=1;
            }
        }

        return ans;
    }
};