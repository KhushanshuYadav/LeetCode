class Solution {

    //by brian kernighan's algo
    int countSetBits(int n){

        int ans=0;

        while(n){

            n=n&(n-1);
            ans++;
        }

        return ans;


    }
public:
    vector<int> countBits(int n) {

        //nlogn

        vector<int>ans;

        for(int i=0;i<=n;i++){

            ans.push_back(countSetBits(i));

        }

        return ans;
        
    }
};