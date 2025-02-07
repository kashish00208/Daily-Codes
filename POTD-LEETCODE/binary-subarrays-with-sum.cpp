class Solution {
public:
    int getSum(vector<int>& nums, int goal){
        if(goal<0)return 0;
        int ans = 0 , right = 0 , left = 0 , sum = 0;

        while(right<nums.size()){
            sum += nums[right];
            while(sum>goal){
                sum -= nums[left];
                left++;
            }
            ans += right-left+1;
            right++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return getSum(nums,goal) - getSum(nums,goal-1);
    }
};