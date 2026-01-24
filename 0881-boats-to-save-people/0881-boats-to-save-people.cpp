class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(),people.end());

        int n=people.size();

        int ans =n;
        
        int i=0;
        int j=n-1;

        while(i<j){

            if(people[i]+people[j]>limit) j--;

            else{
                ans--;
                i++;
                j--;
            }
        }

        return ans;
    }
};