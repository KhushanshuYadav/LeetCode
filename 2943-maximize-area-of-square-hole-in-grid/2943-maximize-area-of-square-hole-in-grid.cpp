class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        int l=1;
        int a=l*l;

        

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int streak=1;
        int maxStreak=1;

        int N=hBars.size();

        for(int i=1;i<N;i++){

            if(hBars[i]==hBars[i-1]+1) {
                streak++;
               
            }
            else streak=1;
            maxStreak=max(maxStreak,streak);
            
        }
        cout<<"1"<<" "<<streak<<endl;
        cout<<"2"<<" "<<maxStreak<<endl;

        int minStreak=INT_MAX;
        minStreak=min(minStreak,maxStreak);

        cout<<"3"<<" "<<minStreak<<endl;

        streak=1;
        maxStreak=1;

        int M=vBars.size();

        for(int i=1;i<M;i++){

            if(vBars[i]==vBars[i-1]+1) {
                streak++;
               
            }
            else streak=1;
            maxStreak=max(maxStreak,streak);
            
        }
        cout<<"4"<<" "<<streak<<endl;
        cout<<"5"<<" "<<maxStreak<<endl;

        minStreak=min(minStreak,maxStreak);
        cout<<"6"<<" "<<minStreak<<endl;

        l+=minStreak;

        return (l*l);
        
    }
};