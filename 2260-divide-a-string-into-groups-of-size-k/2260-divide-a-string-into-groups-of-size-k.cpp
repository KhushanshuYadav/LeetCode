class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {

        int n=s.size();

        vector<string>ans;

        int parts=n/k;

        int lastGrpE=n%k;

       

    

        int i=0;

        while(parts--){
            string temp="";

            int limit=k+i;
            for(;i<limit;i++){
                temp.push_back(s[i]);
            }
            cout<<temp<<endl;
            //i++;
            ans.push_back(temp);
        }

        if(lastGrpE==0) return ans;

        string temp="";

        for(;i<n;i++){
            temp.push_back(s[i]);
        }

        int fills=k-lastGrpE;

        while(fills--){
            temp.push_back(fill);

        }
        ans.push_back(temp);

        return ans;


        
    }
};