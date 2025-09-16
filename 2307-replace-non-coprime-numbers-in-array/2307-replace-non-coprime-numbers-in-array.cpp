class Solution {
    // Your gcd and lcm helper functions are perfect.
    int lcm(int a, int b){
        return ((long long)a * b / gcd(a, b));
    }

    int gcd(int a, int b){
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;

        // 1. Iterate through each number in the input array.
        for (int num : nums) {
            // 2. Add the current number to our result list.
            ans.push_back(num);

            // 3. Start the backward-merging process.
            // This loop continues as long as there are at least two numbers
            // in our result and the last two are non-coprime.
            while (ans.size() >= 2 && gcd(ans.back(), ans[ans.size() - 2]) > 1) {
                
                // Get the last two numbers.
                int n1 = ans.back();
                ans.pop_back();
                int n2 = ans.back();
                ans.pop_back();
                
                // Push their LCM back. The while loop will then repeat the check
                // with this new LCM and the element that came before it.
                ans.push_back(lcm(n1, n2));
            }
        }
        return ans;
    }
};