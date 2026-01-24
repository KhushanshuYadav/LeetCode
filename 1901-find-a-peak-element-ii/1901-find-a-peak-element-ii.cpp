class Solution {

    int delR[2]={0,0};
    int delC[2]={-1,+1};

    bool isPeak(int i,int j,vector<vector<int>>& mat,int& rows,int& cols){

        for(int k=0;k<2;k++){


            int nI=i+delR[k];
            int nJ=j+delC[k];

            if(nI>=0 && nI<rows && nJ>=0 && nJ<cols && mat[i][j]<mat[nI][nJ]) return false;


        }

        return true;
    }

    int findMaxIndex(vector<vector<int>>& mat,int& col,int& rows) {

        int mx=INT_MIN;

        int ans=-1;


        for(int i=0;i<rows;i++){

            if(mat[i][col]>mx){
                mx=mat[i][col];
                ans=i;
            }
        }
        return ans;
        
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        //convert in 1-d and solve like 1D to 2D

        int rows=mat.size();
        int cols=mat[0].size();

        int start=0,end=cols-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            int r=findMaxIndex(mat,mid,rows);

            if(isPeak(r,mid,mat,rows,cols)) return {r,mid};


            else if(mat[r][mid]<mat[r][mid+1]) start=mid+1;

            else end=mid-1;

        }



       

        return {-1,-1};

    }
};