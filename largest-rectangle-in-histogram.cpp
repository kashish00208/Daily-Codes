class Solution {
public:
    vector<int> getPse(vector<int>& heights, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;  // If no smaller element exists, set it to -1
            } else {
                ans[i] = st.top();  // PSE is the index of the smaller element
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> getNse(vector<int>& heights, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = n;  
            } else {
                ans[i] = st.top();  
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = getNse(heights, n);
        vector<int> pse = getPse(heights, n);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1; 
            ans = max(ans, heights[i] * width);  
        }
        
        return ans;
    }
};
