class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

        int i=0;
        int j=0;

        vector<vector<int>>ans;

        int n1=nums1.size();
        int n2=nums2.size();

        while(i<n1 && j<n2){
            
            int k1=nums1[i][0];
            int k2=nums2[j][0];

            if(k1==k2){
                //do sum and push and i++ and j++
                ans.push_back({k1,nums1[i][1]+nums2[j][1]});
                i++;
                j++;

            }
            else if(k1<k2){
                //push k1 and i++
                ans.push_back({k1,nums1[i][1]});
                i++;
            }
            else{
                //push k2 and j++
                ans.push_back({k2,nums2[j][1]});
                j++;
            }

        }

        while(i<n1){
            ans.push_back({nums1[i][0],nums1[i][1]});
            i++;

        }

        while(j<n2){
            ans.push_back({nums2[j][0],nums2[j][1]});
            j++;

        }
        
        return ans;
    }
};