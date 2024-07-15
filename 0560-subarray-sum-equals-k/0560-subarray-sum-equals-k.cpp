class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n=arr.size();
    //vector<int>prefixSum(n);

    unordered_map<int ,int >m;  //we store the frequency of each prefixSum 
    m[0]=1;

    int count=0;
    int prefixSum=0;

    for(int i=0;i<n;i++){
       prefixSum+=arr[i];

       count=count+m[prefixSum-k];  //count will be current count + the occurances of prefixSum-k understand that if prefixSum-k exist then subarray with sum =k will also exist as it wwill be contained in it


       m[prefixSum]++;
    }

    return count;

    }
};