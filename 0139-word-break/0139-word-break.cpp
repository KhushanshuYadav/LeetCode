class Solution {


    //returns true if we can break word from index i to n-1 ATQ 
    bool solve(int i,int& n, unordered_set<string>& dict,string& s, vector<int>& dp){

        //we have reached till end mean in all partions we got valid answer as we call in deep when we get a valid word
        if(i==n) return true; 


        if(dp[i]!=-1) return dp[i];


        //trying all partitions in raange 
        for(int k=i;k<n;k++){

            string temp=s.substr(i,k-i+1);

            //if we found valid word from i to k i.e left portion, go deep i.e check for right partiton 
            if( dict.count(temp) ){

                //if right partition is valid too return true
                if( solve(k+1,n,dict,s,dp) ){
                    return dp[i]=true;

                }

    
            }
        }

        //if any partition is not bale to return true return false;
        return dp[i]=false;
    }


        
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n =s.size();

        unordered_set<string>dict;

        for(string& str:wordDict){
            dict.insert(str);
        }

        vector<int>dp(n,-1);

        return solve(0,n,dict,s,dp);
        
    }
};