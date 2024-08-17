class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();

    //code says buy at minimum price so if currr< min update min
    //profit will be max of max profit annd curr profit

    //to sell at ith keep track of min price till i
    int maxProfit=0;
    int minPrice=INT_MAX;
     
    for(int i=0;i<n;i++){
        minPrice=min(minPrice,arr[i]);
        int profit=arr[i]-minPrice;
        maxProfit=max(maxProfit,profit);
    }
     return maxProfit;
    }
};