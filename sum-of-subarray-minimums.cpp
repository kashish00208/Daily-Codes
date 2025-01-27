class Solution {
public:
    vector<int>prevSmall(vector<int>& arr,int n){
        vector<int>small(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                small[i] = st.top();
            }
            st.push(i);
        }
        return small;
    }
    vector<int>nextSmall(vector<int>& arr,int n){
        vector<int>small(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                small[i] = st.top();
            }
            st.push(i);
        }
        return small;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size() , ans = 0, mod = 1e9 +7;
        vector<int>prev = prevSmall(arr,n);
        vector<int>next = nextSmall(arr,n);
        for(int i=0;i<n;i++){
            int left = i - prev[i];
            int right = next[i] - i;
            ans = (ans + (right * left * (long long)1 * arr[i]) % mod) % mod;
        }
        return ans;
    }
    
};