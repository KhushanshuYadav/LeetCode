class Solution {
    //prev question subSet problem
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();

        // Space optimization;
        vector<bool> nextRow(sum + 1, false); // nextRow==prev State
        // cell i,j stores if there is a
        // subsequence that starts from index i and has sum =j

        nextRow[0] =
            true; // sum==0 subsequence is always possible from any index

        if (arr[n - 1] <= sum)
            nextRow[arr[n - 1]] = true; // for subSeq ending at last index only
                                        // its index value is possible

        for (int i = n - 2; i >= 0; i--) {
            vector<bool> currRow(sum + 1, false);
            currRow[0] = true;
            for (int j = 0; j <= sum; j++) {

                bool ans = false;

                // if sum==j can be achived by no taking i th element i.e from
                // prev subsequence
                if (nextRow[j])
                    ans = true;

                // if above fails we must try to take i th in subsequence

                // if i th >j so it will inc the sum to go beyond so not
                // possible at all
                else if (arr[i] > j)
                    ans = false;

                // id i th <= j so to achive j arr[i] included so check if
                // j-arr[i] can be obtained from prev state
                else {
                    if (nextRow[j - arr[i]])
                        ans = true;
                }

                currRow[j] = ans;

                if (currRow[sum])
                    return true;
            }
            nextRow = currRow;
        }

        return nextRow[sum];
    }

public:
    bool canPartition(vector<int>& nums) {

        // understand
        // both subset if combined should give array back i.e
        // we cannot take two subsets as [1] and [5] from [1,5,11,5]

        // so we see to suffice above condition and to have sum equal

        // each of the subset will have sum of it equal to givenArraySum/2
        // so if sum(arr) is odd we return false a if odd sum then one
        // subset will always have a (sum/2)+1 and other sum/2 i.e can never
        // be equal

        // now if even just check if we have subset with sum = sum(nums)/2
        // if yes return true else false

        int n = nums.size();

        int arraySum = 0;
        for (int& i : nums) {
            arraySum += i;
        }

        if (arraySum % 2 != 0)
            return false;

        bool ans = isSubsetSum(nums,arraySum/2);

        return ans;
    }
};