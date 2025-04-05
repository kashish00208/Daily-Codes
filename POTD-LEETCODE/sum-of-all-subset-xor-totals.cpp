class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int n = nums.size(), subset = 1 << n, ans = 0;
            for(int num = 0; num < subset; num++) {
                int temp = 0;
                for(int i = 0; i < n; i++) {
                    if(num & (1 << i)) {
                        temp ^= nums[i];
                    }
                }
                ans += temp;
            }
            return ans;
        }
    };
    