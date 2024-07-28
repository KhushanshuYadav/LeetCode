class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int>ans;
        int n=asteroids.size();
        stack<int>s;

        for(int &a:asteroids){

            if(s.empty() || a>0) s.push(a);

            else{

                while(!s.empty() && s.top()<abs(a) && s.top()>0){
                    s.pop();
                }

                if(!s.empty() && s.top()==abs(a)){
                    s.pop();
                }

                else{
                    if(s.empty()|| s.top()<0) s.push(a);
                }

            }

        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;


    }
};