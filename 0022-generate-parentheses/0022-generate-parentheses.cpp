class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;

        fun(n,"",0,0,ans);

        return ans;
    }
private:
    void fun(int& n,string temp,int openBCount,int closeBCount,vector<string>& ans){

        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }

        if(openBCount<n)  fun(n,temp+'(',openBCount+1,closeBCount,ans);

        if(closeBCount<openBCount)  fun(n,temp+')',openBCount,closeBCount+1,ans);


        return;


    }
};