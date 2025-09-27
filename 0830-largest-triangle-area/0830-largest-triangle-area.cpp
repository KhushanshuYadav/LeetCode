class Solution {

    double area(vector<int>&p1 ,vector<int>&p2, vector<int>&p3){
        double x1=p1[0];
        double y1=p1[1];

        double x2=p2[0];
        double y2=p2[1];

        double x3=p3[0];
        double y3=p3[1];

        double temp=abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));

        double ans=temp/2;

        return ans;
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {

        int n=points.size();

        double ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){

                    ans=max(ans,area(points[i],points[j],points[k]));

                }
            }
        }
        return ans;
        
    }
};