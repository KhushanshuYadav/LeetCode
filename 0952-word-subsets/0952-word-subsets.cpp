class Solution {
    bool fun1(string& a,vector<int>&freq){

        for(char& c:a){
            if( freq[c-'a']>0 ) freq[c-'a']--;
        }

        for(int&i:freq) cout<<i<<" ";
        cout<<endl;

        for(int& i:freq){
            if(i!=0) return false;
        }

        return true;
        
    }
    vector<int>fun2(string& b){

        vector<int>freq(26,0);

       

        for(char& c:b){
            freq[c-'a']++;
                
        }
        

        return freq;
        
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<string>ans;
        vector<int>freq(26,0);

        for(string& b:words2){

            auto tempFreq=fun2(b);
            for(int i=0;i<26;i++){
                freq[i]=max(freq[i],tempFreq[i]);
            }
        }

        

        for(string& a:words1){
            auto aFreq=fun2(a);
            bool isU=true;
            for(int i=0;i<26;i++){
                if( freq[i] && aFreq[i]<freq[i]){
                    isU=false;
                    break;
                } 
            }
            if( isU ) ans.push_back(a);
        }
        
        return ans;
    }
};