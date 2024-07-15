class Solution {
public:
    int majorityElement(vector<int>& v) {
        unordered_map<int, int> m;
        int n = v.size();

        for (int i = 0; i < n; i++) {

            m[v[i]]++;
        }

        for (auto i : m) {
            if ((i.second) > n / 2) {
                return i.first;
            }
        }

        return 0;
    }
};