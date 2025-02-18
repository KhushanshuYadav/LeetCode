class Solution {
public:
    string smallestNumber(string pattern) {

        int  n=pattern.size();
        
        string ans="";
        stack<int>s;

        for(int i=0;i<=n;i++){
            s.push(i+1);
            if(i==n || pattern[i]=='I'){
                while(!s.empty()){
                    ans.push_back(char(s.top()+'0'));
                    s.pop();
                }
            }
        }

        return ans;
    }
};