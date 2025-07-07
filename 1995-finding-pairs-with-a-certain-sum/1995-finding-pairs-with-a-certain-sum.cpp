class FindSumPairs {
    unordered_map<int,int>m1;//index,element
    unordered_map<int,int>m2;//element,freq
    int n;
    vector<int>nums1;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {

        this->n=nums1.size();
        this->nums1=nums1;
        for(int&i:nums2) m2[i]++;
        for(int i=0;i<nums2.size();i++) m1[i]=nums2[i];
        
    }
    
    void add(int index, int val) {

        int e=m1[index];
        m2[e]--;
        //if(m2[e]==0) m2.erase(m2.find(e));
        m1[index]+=val;
        m2[m1[index]]++;

        
    }
    
    int count(int tot) {
        int ans=0;

        for(int i=0;i<n;i++){

            int e=nums1[i];

            if(m2.count(tot-e)) ans+= m2[tot-e];

        }
        return ans;

    
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */