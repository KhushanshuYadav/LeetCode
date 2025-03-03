class Solution {

public:
    vector<int> pivotArray(vector<int>& arr, int pivot) {
        int n = arr.size();

        vector<int>ans(n);
        //vector<int>vis(n,0);
        int j=0;

        for(int i=0;i<n;i++){

            if(arr[i]<pivot ) {
                ans[j]=arr[i];
                j++;
                //vis[i]=1;
            }

        }

        for(int i=0;i<n;i++){

            if(arr[i]==pivot  ) {
                ans[j]=arr[i];
                j++;
            }

        }

        for(int i=0;i<n;i++){

            if(arr[i]>pivot ) {
                ans[j]=arr[i];
                j++;
            }
        }

        return ans;
    }
};