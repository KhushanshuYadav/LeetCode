class Solution {
    int mod = 1000000007;
    int reverseNumber(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> m; // diff,freq

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int diff=nums[i]-reverseNumber(nums[i]);

            ans+=m[diff];
            ans=ans%mod;

            m[diff]++;
        }

        return ans;
    }
};