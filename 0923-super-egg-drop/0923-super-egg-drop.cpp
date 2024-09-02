class Solution {


    int solve(int e,int f,vector<vector<int>>&dp){
        
        if(e==1) return f;
        
        if(f==0 || f==1) return f;
        
        if(dp[e][f]!=-1) return dp[e][f];
        
        int ans=INT_MAX;
        //APPLYING B.S. FOR K
        
        //we try to throw from each floor in range and takes min 
        //since range of k is sorted so BS
        int left=1;
        int right=f;
        while(left<=right){

            int k=left+(right-left)/2;
            
            //two options break and not break
            
            //if breaks so e dec by 1 and below floors to check only
            //below of left portion of range 
            int breaks=solve(e-1,k-1,dp); 
            
            //if not breaks so e same and above floors to check only
            //upper or right potion of range
            int notBreaks=solve(e,f-k,dp);
            
            //as worst case so take max
            int worstCase=max(breaks,notBreaks);

            //1== curr attempt and worstCase == max of options from here 
            int temp=1+worstCase;

            //as we want more attempts or floors i.e worst case 
            if(breaks>notBreaks){

                right=k-1;



            }
            else{

                left=k+1;

            }
            
            
            
            ans=min(ans,temp);
            
        }
        
        return dp[e][f]=ans;
    }
public:
    int superEggDrop(int k, int n) {

        int e=k;
        int f=n;

        vector<vector<int>>dp(e+1,vector<int>(f+1,-1));
        
        return solve(e,f,dp);
        
    }
};