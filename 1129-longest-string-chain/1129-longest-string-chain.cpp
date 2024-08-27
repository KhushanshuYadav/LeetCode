class Solution {

    bool comp(string& s1,string& s2){

        if( s2.size()!=s1.size()+1 ) return false; 
        //the size of s2 is >s1 but it should be like more than  by one only
        //i.e bigger one should be bigger by one len only

        //NOT EQUAL IS MUST AS WE NEED TO CHECK FOR equal also i.e > fails as if == we need to return false;

        int s1Index=0; //samller string index
        int s2Index=0; //bigger string index

        while( s2Index<s2.size() ){


            if( s1Index<s1.size() && s1[s1Index]==s2[s2Index] ){
                s1Index++;
                s2Index++;
            }
            else{
                s2Index++;
            }
        }
        
        if(s1Index==s1.size() &&  s2Index==s2.size()) return true;
        else return false;



    }
public:
    int longestStrChain(vector<string>& words) {

        int n=words.size();

        sort(words.begin(),words.end(), [&](string& a,string& b){
            return a.size()<b.size();
        });

        
        vector<int>dp(n,1);
        int ans=1;
        for(int i=0;i<n;i++){

            for(int prevIndex=0;prevIndex<i;prevIndex++){

                if( comp(words[prevIndex],words[i]) && (dp[prevIndex] +1> dp[i]) ){

                    dp[i]=dp[prevIndex] +1;
                }

               //ans=max(ans,dp[i]);

               

            }
        }


        return *max_element(dp.begin(),dp.end());

        
    }
};