class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();
        // int ans = nums[0];
        int sum = nums[0];

        int res1 = nums[0];
        int maxEnding1 = nums[0];

        for (int i = 1; i < n; i++) {
            maxEnding1 = max(maxEnding1 + nums[i], nums[i]);
            res1 = max(res1, maxEnding1);
        }
        cout<<res1<<" ";
        

        int res2 = nums[0];
        int maxEnding2 = nums[0];

        for (int i = 1; i < n; i++) {
            maxEnding2 = min(maxEnding2 + nums[i], nums[i]);
            res2 = min(res2, maxEnding2);
        }
        cout<<res2<<" ";

        int ans=max(abs(res1),abs(res2));

        return ans;
    }
};