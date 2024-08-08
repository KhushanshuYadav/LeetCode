class Solution {
private:
    void fun(int begin,string temp, vector<string>& ans,unordered_map<char,vector<char>>&m,string& digits){

        if(temp.size()==digits.size()){
            ans.push_back(temp);
            return;
        }


        for(char c=m[digits[begin]][0];c<=m[digits[begin]][1];c++){
            temp.push_back(c);
            fun(begin+1,temp,ans,m,digits);
            temp.pop_back();

        }
    }
public:
    vector<string> letterCombinations(string digits) {

        if(digits=="") return {};

        unordered_map<char,vector<char>>m;
        m['2']={'a','c'};
        m['3']={'d','f'};
        m['4']={'g','i'};
        m['5']={'j','l'};
        m['6']={'m','o'};
        m['7']={'p','s'};
        m['8']={'t','v'};
        m['9']={'w','z'};

        if(digits.size()==1){
            vector<string>ans;
            for(char c=m[digits[0]][0];c<=m[digits[0]][1];c++){
                string temp="";
                temp.push_back(c);
                ans.push_back(temp);
            }
            return ans;
        }

        vector<string>ans;
        int n=digits.size();

        int begin=0;
        fun(begin,"",ans,m,digits);
        return ans;
        

        



        
    }
};