class Solution {
public:
    int minimumPushes(string word) {

        int n=word.size();
        int ans=0;

        vector<int>freq(26,0);

        for(char& c:word){
            freq[c-'a']++;
           // freq[c-'a'].second=c;

        }

        sort(freq.begin(),freq.end(),greater<int>());

        

        
        for(int i=0;i<26;i++){
            if(i>=0 && i<=7){
                ans=ans+(freq[i]*1);
            }
            else if(i>=8 && i<=15){
                ans=ans+(freq[i]*2);
            }
            else if(i>=16 && i<=23){
                ans=ans+(freq[i]*3);
            }
            else{
                ans=ans+(freq[i]*4);
            }
        }

        return ans;
            
        

        
    }
};