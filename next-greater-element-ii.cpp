class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(); //size of array
        vector<int>ans(n,-1); //vector to store next greater element

        stack<int>st; //storing element in monotonic order
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && nums[i%n]>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                ans[i%n] = st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};