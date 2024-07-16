class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int>s;
        int n=heights.size();
        int maxA=-1;

        for(int i=0;i<=n;i++){

            while( !s.empty() && (i==n || heights[i]<=heights[s.top()]) ){
                int height=heights[s.top()];
                s.pop();

                int width= (s.empty())?i:i-s.top()-1;

                int currA=height*width;

                maxA=max(maxA,currA);
            }

            s.push(i);
        }

        return maxA;
        
    }
};