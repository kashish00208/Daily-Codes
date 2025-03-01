class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> ans;
            deque<int> dq;
            
            for (int i = 0; i < nums.size(); i++) {
                // Remove elements outside the current window
                if (!dq.empty() && dq.front() <= i - k) {
                    dq.pop_front();
                }
                
                // Maintain deque in monotonic order of elements
                while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                    dq.pop_back();
                }
                
                // Add current element's index to deque
                dq.push_back(i);
                
                // Add the front element of the deque to the result of current window
                if (i >= k - 1) {
                    ans.push_back(nums[dq.front()]);
                }
            }
            
            return ans;
        }
    };
    