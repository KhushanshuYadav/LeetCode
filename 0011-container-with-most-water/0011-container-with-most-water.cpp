class Solution {
public:
    int maxArea(vector<int>& height) {

        int n=height.size();

        int ans=0;

        int i=0;
        int j=n-1;

        while(i<j){

            if(height[i]<=height[j]){
                ans=max(ans,abs(i-j)*height[i]);
                i++;
            }
            else{
                ans=max(ans,abs(i-j)*height[j]);
                j--;
            }
          
        }

        return ans;
        
    }
};