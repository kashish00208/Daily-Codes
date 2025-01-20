class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i = 0, len = 0, current = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            while ((current & nums[j]) != 0) {
                current ^= nums[i];
                i++;
            }
            current |= nums[j];
            len = max(len, j - i + 1);
        }
        
        return len;
    }
};
//sliding window approach