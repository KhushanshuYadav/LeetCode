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

       //auto graph =buildGraph(beginWord,wordList);
        
        //int ans=INT_MAX;

        unordered_set<string>words(wordList.begin(),wordList.end());

        queue<string>q;

        q.push(beginWord);

        unordered_set<string>vis;
        vis.insert(beginWord);

        int step=1;

        while(!q.empty()){

            int size=q.size();

            for(int i=0;i<size;i++){
                
                string s=q.front();
           
                q.pop();

                for(int j=0;j<s.size();j++){

                    for(char n='a';n<='z';n++){
                        string temp=s;
                        temp[j]=n;

                        if(temp==endWord && words.count(temp)) return step+1;

                        if(words.count(temp) && !vis.count(temp)){
                            
                            cout<<s<<" "<<temp<<" "<<step<<endl;
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }

            }

            step++;
            

        }

        return 0;



    }
};