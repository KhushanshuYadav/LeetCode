class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
      
      vector<int>a(n,1); //at 0th sec all are one;
      int mod=1000000007;
      
      
      
      for(int count =1;count<=k;count++){
        
        for(int i=1;i<n;i++){ 
              a[i]=(a[i]+a[i-1])%mod;
        }
        
      }
      
      
      return a[n-1];
      
      
      
      
        
    }
};