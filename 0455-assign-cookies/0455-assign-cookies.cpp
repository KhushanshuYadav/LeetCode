class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0;

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n =s.size();
        int m=g.size();

        int count=0;

        while(i<n && j<m){
            if(s[i]<g[j]){
                i++;

            }
            else{
                i++;j++;
                count++;
            }
        }

        return count;
    }
};