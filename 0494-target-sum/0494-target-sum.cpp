class Solution {
    int perfectSum(vector<int>& arr, int n, int sum)
	{
        // Your code goes here
        
        //int ans=solve(0,0,n,sum,arr,dp);
        
        //ans=ans%mod;
        //return ans;
        
        //TABULATION
        
        
        //cell i,j stores count of subsets having sum==j starting from element at i th index to last index (any subset fromindex i to last)
    
        vector<int>nextRow(sum+1,0);
        
        
        
        /*for(int row=0;row<n;row++){
            dp[row][0]=1;
            
        }*/
        nextRow[0]=1;
        if(arr[n-1]<=sum) nextRow[arr[n-1]]=1;
        
        if(arr[n-1]==0) nextRow[arr[n-1]]=2;  //
        
        for(int i=n-2;i>=0;i--){
            
            vector<int>currRow(sum+1,0);
            
            
            for(int j=0;j<=sum;j++){
                
                int ans=0;
                
                int notTake=(nextRow[j]);
                
                int take=0;
                
                if(arr[i]<=j){
                    
                    take=(nextRow[j-arr[i]]);
                    
                }
                
                ans=(notTake+take);
                
                
                
                
                
                currRow[j]=(ans);
                
            }
            nextRow=currRow;
        }
        
        
        return nextRow[sum];
        
        
        
        
        
        
        
	}

    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        
        int totalSum=0;
        
        for(int i=0;i<n;i++){
            totalSum+=arr[i];
        }
        int sum=(totalSum-d)/2;
        
        if( (totalSum-d)<0 || (totalSum-d)%2!=0 ) return 0;
        int count=perfectSum(arr,n,sum);
        
        return (count);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //IF you look closely it is the problem of count partition with given difference problem

        //here diff =target

        int n =nums.size();

        return countPartitions(n,target,nums);
        
    }
};