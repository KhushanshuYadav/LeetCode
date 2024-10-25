class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        unordered_set<string>s(folder.begin(),folder.end());
        vector<string>ans;

        for(string currF:folder){

            bool flag=false;
            string temp=currF;

            while(!currF.empty()){

                auto ind= currF.find_last_of('/');

                currF=currF.substr(0,ind);

                if(s.count(currF)){
                    flag=true;
                    break;
                }
            }

            if(!flag) ans.push_back(temp);

        }

        return ans;
        
    }
};