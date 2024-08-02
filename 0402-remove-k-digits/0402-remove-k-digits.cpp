class Solution {
private:
    bool isAllSame(string& num) {
        for (int i = 1; i < num.size(); i++) {
            if (num[i] != num[i - 1])
                return false;
        }

        return true;
    }

public:
    string removeKdigits(string num, int k) {

        int n = num.size();

        if (k >= n)
            return "0";

        /* if(isAllSame(num)){
             num.erase(0,k);
             return num;
         }*/

        stack<int> s;
        s.push(0);

        for (int i = 1; i < n; i++) {

            while (!s.empty() && k > 0 && num[i] < num[s.top()]) {
                k--;
                s.pop();
            }

            s.push(i);
        }

        while (!s.empty() && k) {
            s.pop();
            k--;
        }

        if(s.empty()) return "0";

        string ans="";

        while(!s.empty()){

            ans.push_back(num[s.top()]);
            s.pop();


        }

        while(ans.size()>0 && ans.back()=='0') ans.pop_back();

        if(ans.size()==0) return "0";

        reverse(ans.begin(),ans.end());
        return ans;
    }
};