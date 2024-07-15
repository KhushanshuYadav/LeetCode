class Solution {
public:

    bool bS(vector<int>&v,int start,int end,int target){
        while(start<=end){
            int mid=(start+end)/2;

            if(v[mid]==target) return true;

            else if(v[mid]>target) end=mid-1;

            else start=mid+1;
        }


        return false;
    }


    bool searchMatrix(vector<vector<int>>& v, int target) {

        int n=v.size();
        int m=v[0].size();

        int start=0,end=(n*m-1);

        while(start<=end){
            int mid=start+(end-start)/2;

            int row=mid/m,col=mid%m;

            if(v[row][col]==target) return true;

            else if(v[row][col]>target) end=mid-1;

            else start=mid+1;
        }


        return false;
    }
};