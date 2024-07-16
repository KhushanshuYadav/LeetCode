class Solution {
public:

     bool isPair(char a,char b){
        if(a=='(' && b==')') return true;
        if(a=='{' && b=='}') return true;
        if(a=='[' && b==']') return true;
        
        return false;
        
    }
    bool isValid(string s) {
        stack<char>st;

        for(char c:s){
            if(c=='(' || c=='[' || c=='{') st.push(c);

            else{

                if(st.empty()) return false;

                else if( !isPair(st.top(),c) ) return false;

                else st.pop();

            }
        }

        return ( st.empty() );
        
    }
};