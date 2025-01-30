class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, n = heights.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();
                int nse = i, pse = st.empty() ? -1 : st.top();
                ans = max(ans, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = n, element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            ans = max(ans, heights[element] * (nse - pse - 1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>> pSum(n, vector<int>(m, 0)); 
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1') {
                    sum++; 
                } else {
                    sum = 0; 
                }
                pSum[i][j] = sum; 
            }
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, largestRectangleArea(pSum[i]));
        }

        return ans;
    }
};
