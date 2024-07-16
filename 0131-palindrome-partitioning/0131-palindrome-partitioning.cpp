class Solution {
public:

    bool isPallindrome(string s,int l,int r){
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    void fun(int begin,string& s,vector<string>& temp,vector<vector<string>>& ans){

        if(begin==s.size()){
            ans.push_back(temp);
            return;
        }
        //basically we create partiton from begin to i in left side and chech if it is pallindrome if yes then go to right of partition and do the same

        for(int i=begin;i<s.size();i++){
            if(isPallindrome(s,begin,i)){

                temp.push_back(s.substr(begin,i-begin+1));
                fun(i+1,s,temp,ans);
                temp.pop_back();
            }
        }


    }
    vector<vector<string>> partition(string s) {

        vector<vector<string>>ans;
        vector<string>temp;
        int begin=0;

        fun(begin,s,temp,ans);
        
        return ans;
        
    }
};