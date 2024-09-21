class Solution {

    void solve(int i,vector<int>&ans,int& n){
        if(i>n) return;

        ans.push_back(i);

        for(int j=0;j<=9;j++){

            int temp=(i*10)+j;

            if(temp<=n){

                solve(temp,ans,n);

            }
        }
    }

public:
    vector<int> lexicalOrder(int n) {

        vector<int>ans;

        for(int i=1;i<=9;i++){

            solve(i,ans,n);

        }



        return ans;
        
    }
};