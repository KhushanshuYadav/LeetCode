class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<long,vector<long>,greater<long>>pq(nums.begin(),nums.end());


        int ans=0;

        while(pq.top()<k){  //as soon as smallest element gets >=k so all gets >=k

            long x=pq.top();
            pq.pop();
            //if(x>=k) continue;

            long y=pq.top();
            pq.pop();

            long val=((min(x,y)*(long)2))+max(x,y);

            pq.push(val);

            ans++;
        }

        return ans;
        
    }
};