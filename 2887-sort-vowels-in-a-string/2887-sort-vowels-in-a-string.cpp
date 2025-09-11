class Solution {
public:

    bool isVowel(char& c){
        return (c=='A' || c=='E' || c=='I' ||c=='O' || c=='U' ||c=='a'|| c=='e'|| c=='i'||c=='o'||c=='u');
    }


    string sortVowels(string s) {

        priority_queue<char,vector<char>,greater<char>>pq;

        for(char&c:s) if(isVowel(c)) pq.push(c);

        for(char&c:s) {
            if(isVowel(c)){
                c=pq.top();
                pq.pop();
            }
        }

        return s;
        
    }
};