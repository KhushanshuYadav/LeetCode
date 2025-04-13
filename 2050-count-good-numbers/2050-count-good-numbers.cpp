class Solution {
    int mod=1000000007;
    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;}
public:
    int countGoodNumbers(long long n) {

        //long long ans=1;
        
        long long evens=(n+1)/2;
        long long odds=n-evens;

        long long ans=modPow(5LL,evens)*modPow(4LL,odds);

        ans=ans%mod;

        return ans;
        
    }
};