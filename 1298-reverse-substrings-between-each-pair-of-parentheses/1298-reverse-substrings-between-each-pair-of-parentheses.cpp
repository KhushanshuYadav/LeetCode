class Solution {
public:
    string reverseParentheses(string s) {

        /*stack<char>st;
        for(char& c:s){
            if(c==')'){
                string temp="";
                while(st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();

                for(char &i:temp){
                    st.push(i);
                }
            }

            else st.push(c);
        }

        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;*/

        //for ABOVE  LEET CODE SYAS TC IS O(N)

        //BELOW IS WORMHOLE TELEPORTATION TECHNIQUE
        //as we know paranthesis are balanced so there is a open for closing and closing for open 
        //so we jump to opposite bracket and move in opppsite direction

        stack<int>st;
        int n=s.size();
        vector<int>opp(n,-1);

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i); //openinh index in pushed
            }
            else if(s[i]==')'){
                opp[i]=st.top();
                opp[st.top()]=i;
                st.pop();
            }
        }

        string ans="";
        int dir=1; //1 says go in forward direction ;
        for(int i=0;i<n;i+=dir){
            //i will either go forward or backward in a itration so if dir==-1 so dec i;

            if(s[i]=='(' || s[i]==')'){ 
                //jump to other end 
                i=opp[i];
                dir*=-1; //reverse direction of prev;

            } 

            else ans.push_back(s[i]);
        }

        return ans;


        
    }
};