class Solution {
public:
    bool isOverlapping(vector<int>&v1,vector<int>&v2){

        return ( max(v1[0],v2[0])<=min(v1[1],v2[1]) );

    } 

    void merge(vector<int>&v1,vector<int>&v2,vector<int>&ans){
        ans[0]=min(v1[0],v2[0]);
        ans[1]=max(v1[1],v2[1]);
        return;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>>ans;
        

        int n=intervals.size();
        int i=0;



        //pushing all non overlapping in ans
        while(i<n &&  intervals[i][1]<newInterval[0] ){ //can not call isoverlapping finction as here we need to maintain the sorted order i.e new starts after old ends so sorted 

            ans.push_back(intervals[i]);
            i++; 

        }

        //puhsing the overlapping i.e merging all overlapping ones and pushing it;

        while(i<n && isOverlapping(intervals[i],newInterval) ){ //here can write intervals[i][0]<=nI[1] i.e new starts before old ends

            merge(intervals[i],newInterval,newInterval);
            i++;
        }
        ans.push_back(newInterval);

        //pushing  the right non overlapping portion of newInterval
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }






        return ans;
        
    }
};