class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n=blocks.size();

        int bCount=0;
        int ans=INT_MAX;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W') bCount++;
        }

        ans=min(bCount,ans);

        for(int i=k;i<n;i++){

            if(blocks[i-k]=='W') bCount--;

            if(blocks[i]=='W') bCount++;

            ans=min(ans,bCount);
        }

        return ans;
        
    }
};