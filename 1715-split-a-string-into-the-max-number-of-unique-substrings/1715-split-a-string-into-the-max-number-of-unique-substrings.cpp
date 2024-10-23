class Solution {

    void solve(int begin, string& str, unordered_set<string>& s, int& ans) {

        if (begin == str.size()) return;

        string temp = "";

        for (int j = begin; j < str.size(); j++) {

            temp.push_back(str[j]);

            if (!s.count(temp)) {
                s.insert(temp);
                int x = s.size();
                ans = max(ans, x);
                solve(j + 1, str, s, ans);
                s.erase(s.find(temp));
            }

            //else solve(j + 1, str, s, ans);
        }
    }

public:
    int maxUniqueSplit(string str) {

        unordered_set<string> s;

        int ans = 0;

        solve(0, str, s, ans);

        return ans;
    }
};