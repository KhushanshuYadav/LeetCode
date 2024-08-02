class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int ans=0;
        int winLen=1;
        for(int i=1;i<n+k-1;i++){
            if(colors[i%n]!=colors[(i-1)%n]) winLen++;
            else winLen=1;

            if(winLen>=k) ans++;
        }

        return ans;
    }
};