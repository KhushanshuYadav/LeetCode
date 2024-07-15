class Solution {
public:
   
    void merge(vector<int>&nums,int low,int mid,int high){

        int n1=mid-low+1;
        int n2=high-(mid+1)+1;


        vector<int>left(n1);
        vector<int>right(n2);

        for(int i=0;i<n1;i++) left[i]=nums[low+i];
        for(int i=0;i<n2;i++) right[i]=nums[mid+1+i];

        int k=low,i=0,j=0;

        while(i<n1&&j<n2){
            if(left[i]<=right[j]){
                nums[k++]=left[i++];
            }
            else{
               nums[k++]=right[j++] ;
            }
        }
        
        while(i<n1){
            nums[k++]=left[i++];
        }
        while(j<n2){
            nums[k++]=right[j++];
        }


    }

    int countPairs(vector<int>&nums,int low,int mid,int high){

        int j=mid+1;
        int ans=0;

        for(int i=low;i<=mid;i++){

            //long long int x=2*nums

            while(j<=high && nums[i]>2L*nums[j]) j++;

            ans+=(j-(mid+1)) ;//the current j has not been checked for pair it will be checked in next iteration j++ to gte length
        }

        return ans;
    }
    int mergeSort(vector<int>&nums,int low,int high){
        int ans=0;
        if(low>=high) return ans;
            int mid=low+(high-low)/2;
            ans+=mergeSort(nums,low,mid);
            ans+=mergeSort(nums,mid+1,high);
            ans+=countPairs(nums,low,mid,high);
            merge(nums,low,mid,high);
            return ans;
            
        

       
    }
    int reversePairs(vector<int>& nums) {

        
        return mergeSort(nums,0,nums.size()-1);
        
    }
};