class Solution {

    bool isPallindrome(int& s,int& e,string& str){

        int i=s;
        int j=e;

        while(i<j){
            //not <= as single char is always pallindrom

            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    //returns min cuts needed to make substr from i to n-1 index a pallindrome

    //left portion i to k(cut index) right portion k+1 to n-1
    int solve(int i ,string& s,int& n, vector<int>&dp){

        if(i==n) return 0;
        //we are also making an cut at last index
        

        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        for(int k=i;k<n;k++){
            //cut position

            if( isPallindrome(i,k,s) ){
                //if left portion is pallindrome then onr cut is must 
                //so find cuts in next portion and add one for current

                int temp=solve(k+1,s,n,dp)+1;

                ans=min(ans,temp);

            }
        }

        return dp[i]=ans;

        
        
    }
public:
    int minCut(string s) {

        //undertand answer is always possible if we make n-1 cuts i.e convert in single char   

        int n=s.size();

        vector<int>dp(n,-1);

        return solve(0,s,n,dp)-1;
        //as we also cut at last index it gives one extra cut
        //A | B |C | last cut is not needed
        
    }
};