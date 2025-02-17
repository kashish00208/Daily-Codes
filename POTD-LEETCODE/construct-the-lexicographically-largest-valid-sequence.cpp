class Solution {
    bool helper(vector<int>& ans, vector<bool>& used, int n, int index) {
        if (index == ans.size())
            return true;
        if (ans[index] != 0)
            return  helper(ans, used, n, index + 1);
        for (int i = n; i >= 1; i--) {
            if (used[i])
                continue;
            ans[index] = i;
            used[i] = true;
            if (i == 1) {
                if (helper(ans, used, n, index + 1))
                    return true;
            }
            else if (index + i < ans.size() && ans[index + i] == 0) {
                ans[index + i] = i;
                if (helper(ans, used, n, index + 1))
                    return true;
                ans[index + i] = 0;
            }
            ans[index] = 0;
            used[i] = false;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n - 1, 0);
        vector<bool> used(n + 1, false);
        helper(ans,used, n, 0);
        return ans;
    }
};