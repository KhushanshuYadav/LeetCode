class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {

        int MOD=1000000007;

        vector<int>powers;

        int count=0;
        while(n){

            if(n&1) powers.push_back(1<<count);
            n=n>>1;
            count++;
        }

        for(int&i:powers) cout<<i<<" ";

        vector<int>ans;

        for(auto&q:queries){
            long long sum=1;
            for(int i=q[0];i<=q[1];i++){

                
                sum=(sum*powers[i])%MOD;
            }
            ans.push_back(sum);
        }

        
        return ans;
        
    }
};