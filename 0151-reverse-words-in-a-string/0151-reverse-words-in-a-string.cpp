class Solution {
public:
    string reverseWords(string s) {

        int n=s.size();
        string ans="";

        int left=0,right=0;


        while(left<n && s[left]==' '){
            left++;
        }

        right=left;

        while(right<n){

            string temp="";

            if(s[right]==' '){
                right++;
                continue;
            }

            left=right;

            while(right<n && s[right]!=' '){

                temp.push_back(s[right]);




                right++;
            }

            reverse( temp.begin(),temp.end() );

            if(ans==""){
                //reverse( temp.begin(),temp.end() );
                ans.append( temp );

            } 
            else{

                

                ans.append(" "+temp);

            }

            
           

            //right++           
        }

        reverse(ans.begin(),ans.end());

        return ans;


        
        
    }
};