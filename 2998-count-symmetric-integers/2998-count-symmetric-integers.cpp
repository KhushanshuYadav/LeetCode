class Solution {
public:
    int countSymmetricIntegers(int low, int high) {

        int ans=0;
        for(int i=low;i<=high;i++){

            string s=to_string(i);

            if(s.size()%2!=0) continue;

            int fSum=0;
            int bSum=0;
            for(int j=0;j<(s.size()/2);j++){

                fSum+=(s[j]-'0');
                bSum+=(s[s.size()-j-1]-'0');

            }

            if(fSum==bSum) ans++;

        }

        return ans;
        
    }
};