class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int left = 0, right = 0, count = 0;
        int n = nums.size();
        
        while (right < n) {
            mpp[nums[right]]++;

            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                }
                left++;
            }

            count += right - left + 1;
            right++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
};
