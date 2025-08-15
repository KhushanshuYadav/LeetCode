class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n<=0) return false;
        double l=log(n)/log(4);

        return floor(l)==l;
    }
};