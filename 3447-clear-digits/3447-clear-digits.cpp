class Solution {
public:
    string clearDigits(string s) {

        int n=s.size();

        stack<char>st;
        st.push(s[0]);

        for(int i=1;i<n;i++){

            if( !st.empty() && isdigit(s[i]) && isalpha(st.top()) ) st.pop();

            else st.push(s[i]);

        }

        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};