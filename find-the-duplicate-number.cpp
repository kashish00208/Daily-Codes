class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int n = nums.size();    
    int hash[n];
    memset(hash,0,sizeof(hash)); 
	for(int i=0;i<nums.size();i++){
		hash[nums[i]] += 1;
	}
	for(int j=1;j<nums.size();j++){
		if(hash[j] > 1){
			return j;
		}
	}
	return -1;
    }
};