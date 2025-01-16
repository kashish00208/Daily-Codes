class Solution {
public:
    vector<int> findPse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
             st.push(i);
        }
        return ans;
    }

    vector<int> findNse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,n);
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
             while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> NSE = findNse(arr);
        vector<int> PSE = findPse(arr);
        int total = 0, mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            int left = i - PSE[i];
            int right = NSE[i] - i;
            total = (total + (right * left * (long long)1 * arr[i]) % mod) % mod;
        }
        return total;
    }
};
