class Solution {

    bool isValid(int start,int sum,string& s,int& target,vector<vector<int>>dp){

        if(start==s.size()){
            if(sum==target) return true;
            return false;
        }

        if(sum>target) return false;

        if (dp[start][sum] != -1) return dp[start][sum];

        bool partitionFound=false;
        for(int i=start;i<s.size();i++){
            string prevIS=s.substr(start,i-start+1);
            int prevI=stoi(prevIS);

            partitionFound=partitionFound||isValid(i+1,sum+prevI,s,target,dp);


            //if any partition is found
            if(partitionFound) return true;
        }

        return dp[start][sum]=partitionFound;

    

    }
     bool canPartition(string stringNum, int target) {
        // Valid Partition Found
        if (stringNum == "" && target == 0) return true;

        // Invalid Partition Found
        if (target < 0) return false;

        // Recursively check all partitions for a valid partition
        for (int index = 0; index < stringNum.size(); index++) {
            string left = stringNum.substr(0, index + 1);
            string right = stringNum.substr(index + 1);
            int leftNum = stoi(left);

            if (canPartition(right, target - leftNum)) return true;
        }
        return false;
    }

    bool canPartition(int  n, int target) {

        if(target<0 || n<target) return false;

        if(n==target) return true;

        return(
            canPartition(n/10,target-(n%10))
            ||
            canPartition(n/100,target-(n%100))
            ||
            canPartition(n/1000,target-(n%1000))
        );
        
    }
public:
    int punishmentNumber(int n) {

        int ans=0;

        for(int i =0;i<=n;i++){


            int sq=i*i;
            string sqString=to_string(sq);

            //vector<vector<int>>dp(sqString.size(),vector<int>(i+1,-1));

            if(canPartition(sq,i)){

                ans+=sq;

            }
        }

        return ans;
        
    }
};