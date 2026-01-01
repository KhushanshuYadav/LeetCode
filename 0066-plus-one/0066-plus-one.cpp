class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n=digits.size();

        int carry=0;

        for(int i=n-1;i>=0;i--){

            if(digits[i]==9){
                carry=1;
                digits[i]=0;
            }

            else{
                carry=0;
                digits[i]++;

                return digits;
            }

        }

        digits.insert(digits.begin(),carry);

        return digits;
        
    }
};