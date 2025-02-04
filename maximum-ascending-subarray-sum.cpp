class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0] , maxi = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                maxi += nums[i];
               
            }else{
                maxi = nums[i];
            }
            ans = max(ans,maxi);
        }
        return ans;
    }
};