class Solution {

    string solve(string temp,unordered_set<string>s,int&n){

        if(temp.size()==n){

            if(!s.count(temp)){
                
                return temp;

            } 

            return "";

        }

        string temp2=solve(temp+'0',s,n);

        if(temp2.size()>0) return temp2;

        //as zero means not found

        return solve(temp+'1',s,n);
        //as one call will definately give answer and if not +'0' then +'1'

        
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {

        string ans;
        int  n=nums.size();

        for(int i=0;i<n;i++){

            char c=nums[i][i];

            ans.push_back(c=='1'?'0':'1');

        }

        return ans;

        
    }
};