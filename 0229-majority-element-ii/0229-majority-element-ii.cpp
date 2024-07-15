class Solution {
public:
    vector<int> majorityElement(vector<int>&v) {
        int n=v.size();
        if(n==1) return {v[0]};

        int e1=INT_MIN,e2=INT_MIN;
        int c1=0,c2=0;

        for(int i=0;i<n;i++){

            if(c1==0 && v[i]!=e2){
                e1=v[i];
                c1=1;
            }
            else if(c2==0 && v[i]!=e1){
                c2=1;
                e2=v[i];
            }
            else if(v[i]==e1) c1++;

            else if(v[i]==e2) c2++;

            else{
                c1--;
                c2--;
            }

        }

        c1=0;
        c2=0;


        for(int i=0;i<n;i++){
            
            if(v[i]==e1) c1++;
            else if(v[i]==e2) c2++;
        }

        vector<int>ans;

        if(c1>n/3) ans.push_back(e1);
        if(c2>n/3) ans.push_back(e2);



        return ans;
        
    }
};