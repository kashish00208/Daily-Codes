class Solution {
public:
    int getPartitions(vector<int>& nums,int mid){
        int partition = 1;
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                partition++;
                sum = nums[i];
            }
        }
        return partition;
    }
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(),nums.end());
        int end = accumulate(nums.begin(),nums.end(),0);
        while(start<=end){
            int mid = (start+end)/2;
            int partition = getPartitions(nums,mid);
            if(partition>k){
                start = mid+1;
            }
            else{
                end = mid -1;
            }
        }
        return start;
    }
};