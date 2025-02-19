class Solution {
    void solve(int start, string temp,vector<string>& sV,int& n){

        if(start==n) {
            cout<<temp<<endl;
            sV.push_back(temp);
            return;
        }

        for(char c='a';c<='c';c++){
 
            if( !temp.empty() && temp.back()==c ) continue;

            solve(start+1,temp+c,sV,n);
        }
    }
public:
    string getHappyString(int n, int k) {

        vector<string>sV;
        string temp="";
        solve(0,temp,sV,n);
        
        int size=sV.size();
        if(k>size) return "";

        string ans;
        int i=0;
        while(k--){
            ans=sV[i];
            i++;
        }
        return ans;
        
    }
};