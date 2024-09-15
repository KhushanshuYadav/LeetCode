class Solution {

    bool isVowel(char& c){
        return ( c=='a' ||  c=='e' ||  c=='i' ||  c=='o' ||  c=='u');
    }

    bool allEven(unordered_map< char,deque<int> >& m){

        if( m['a'].size()%2!=0 ){
            return false;
        }

        if( m['e'].size()%2!=0 ){
            return false;
        }

        if( m['i'].size()%2!=0 ){
            return false;
        }
            

        if( m['o'].size()%2!=0 ){
            return false;
        }
            

        if( m['u'].size()%2!=0 ){
            return false;
        }

        return true;
    }

public:
    int findTheLongestSubstring(string s) {

        int ans=0;

        int n=s.size();

        unordered_map<string,int>m;   //state to index;

        vector<int>stateR(5,0);  //a,e,i,o,u
        
        string currState="00000";

        m[currState]=-1;  //intial with no char

        for(int i =0;i<n;i++){

            if(s[i]=='a'){
                stateR[0]=(stateR[0]^1);

            }
            else  if(s[i]=='e'){
                stateR[1]=(stateR[1]^1);

            }
            else  if(s[i]=='i'){
                stateR[2]=(stateR[2]^1);

            }
            else  if(s[i]=='o'){
                stateR[3]=(stateR[3]^1);

            }
            else  if(s[i]=='u'){
                stateR[4]=(stateR[4]^1);

            }

            currState="";
            for(int& i:stateR){
                currState.push_back(char(i+'0'));
            }

            if(m.count(currState)){

                ans=max(ans,i-m[currState]);

            }
            else{
                m[currState]=i;
            }
        }

        return ans;
        
    }
};