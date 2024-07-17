class Solution {
    private:

    void merge(vector<pair<int,int>>& nums2,int start,int mid,int end,vector<int>& ans){
        int n1=mid-start+1;
        int n2=end-(mid+1)+1;
        int c=0;

        /*vector< pair<int,int> >left;
        vector< pair<int,int> >right;

        for(int i=0;i<n1;i++) left.push_back(nums2[i]);
        for(int i=0;i<n2;i++) right.push_back(nums2[mid+1+i]);*/

        
        vector<pair<int, int>> left(nums2.begin() + start, nums2.begin() + mid + 1);
        vector<pair<int, int>> right(nums2.begin() + mid + 1, nums2.begin() + end + 1);

        

        int i=0;
        int j=0;
        int k=start;
        while(i<n1 && j<n2){

            if(left[i].first<=right[j].first){

                nums2[k++]=right[j++];
                
                
               
            }

            else{

                 ans[left[i].second] += (n2- j);


                nums2[k++] = left[i++];

                


                
               


            }
        }

        while(i<n1) nums2[k++]=left[i++];
        while(j<n2) nums2[k++]=right[j++];
    }
   

    


    

    void mergeSort(vector<pair<int,int>>& nums2,int start,int end,vector<int>& ans){

        

        if(start<end){
            int mid=start+(end-start)/2;
            mergeSort(nums2,start,mid,ans);
            mergeSort(nums2,mid+1,end,ans);
            merge(nums2,start,mid,end,ans);
        }

        
    }
        
public:
    vector<int> countSmaller(vector<int>& nums) {

        int n=nums.size();
        vector<int>ans(n,0);
        vector<pair<int,int>>nums2(n);//elements and its corresponding index
        for(int i=0;i<n;i++){
            nums2[i].first=nums[i];
            nums2[i].second=i;
        }

        mergeSort(nums2,0,n-1,ans);
        return ans;
        
    }
};