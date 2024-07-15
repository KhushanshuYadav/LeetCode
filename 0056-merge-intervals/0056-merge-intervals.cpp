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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());

        int n=intervals.size();
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);

        for(int i=1;i<n;i++){

            if( isOverlapping(intervals[i],ans.back()) ){
                merge(intervals[i],ans.back(),ans.back());
            }

            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
        
    }
};