class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right = 0 , left = 0 , flips = 0 , ans = 0;
        while(right<nums.size()){
            if(nums[right]==0){
                flips++;
            }
            while(flips>k){
                if(nums[left]==0){
                    flips--;
                }
                left++;
            }
            ans = max(ans , right-left+1);
            right++;
        }
        return ans;
    }
};