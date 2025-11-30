class Solution {

    bool varyByOneChar(string& s1, string s2){

        bool flag=false;
        for(int i=0;i<s1.size();i++){

            if(s1[i]!=s2[i]){
                if(flag) return false;
                flag=true;
            }
        }

        return flag?true:false;
    }

    unordered_map<string,unordered_set<string>>buildGraph(string& beginWord, vector<string>& wordList){

        unordered_map<string,unordered_set<string>>graph;

        for(auto&s:wordList){
            if(varyByOneChar(beginWord,s)){
                graph[beginWord].insert(s);
                graph[s].insert(beginWord);
            }
        }

        for(auto&s1:wordList){

            for(auto&s2:wordList){

                if(varyByOneChar(s1,s2)){
                    graph[s1].insert(s2);
                    graph[s2].insert(s1);
                }

            }

        }

        return graph;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        auto graph =buildGraph(beginWord,wordList);

        for(auto&[s1,s]:graph){
            cout<<s1<<"->";
            for(auto&s2:s){
                cout<<s2<<" ";
            }
            cout<<endl;
        }

        int ans=INT_MAX;

        queue<pair<string,int>>q;

        q.push({beginWord,1});

        unordered_set<string>vis;
        vis.insert(beginWord);

        while(!q.empty()){
            string s=q.front().first;
            int step=q.front().second;
            q.pop();

            step++;


            for(auto& adj:graph[s]){


                if(!vis.count(adj)){
                    if(adj==endWord) ans=min(ans,step);
                    q.push({adj,step});
                    vis.insert(adj);
                }


            }

            

            cout<<s<<" "<<ans<<endl;
        }


        return ans==INT_MAX?0:ans;




    }
};