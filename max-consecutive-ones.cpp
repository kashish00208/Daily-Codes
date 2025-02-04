class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0 , maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                maxi++;
                ans = max(maxi,ans);
            }else{
                maxi = 0;
            }
        }
        return ans;
    }
};