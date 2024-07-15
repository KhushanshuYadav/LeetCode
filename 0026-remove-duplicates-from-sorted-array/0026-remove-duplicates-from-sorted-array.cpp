class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int j=0;
        int n=arr.size();
	for(int i=1;i<n;i++){
		if(arr[j]!=arr[i]){
			arr[j+1]=arr[i];
			j++;
		}
		

	}

	

	

	return j+1;
    }
};