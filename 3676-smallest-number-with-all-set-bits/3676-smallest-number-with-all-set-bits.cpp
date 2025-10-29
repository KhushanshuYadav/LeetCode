class Solution {
public:
    int smallestNumber(int n) {

        

        set<int>s;

        for(int i=0;i<=n;){
            s.insert((2*i)+1);
            i=(2*i)+1;
        }

        int ans=*lower_bound(s.begin(),s.end(),n);

        return ans;


        
    }
};