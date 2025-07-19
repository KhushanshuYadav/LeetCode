class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        sort(folder.begin(),folder.end(),[&](string& s1,string& s2){return s1.size()<s2.size();});

        unordered_set<string>st;

        vector<string>ans;

        for(string& s:folder){

            cout<<"s "<<s<<endl;

            int n=s.size();

            bool flag=false;

            string temp="";

            temp.push_back(s[0]);

            for(int i=1;i<n;i++){

                if(s[i]!='/') temp.push_back(s[i]);

                else{
                    cout<<"temp "<<temp<<endl;

                    if(st.count(temp)){
                        flag=true;
                        break;

                    }
                    else {
                        temp.push_back(s[i]);
                        continue;
                    }
                }
            }
            st.insert(s);

            cout<<"flag "<<flag<<endl;

            if(!flag) ans.push_back(s);
        }



        return ans;
        
    }
};