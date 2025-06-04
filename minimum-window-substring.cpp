class Solution {
public:
    string minWindow(string s, string t) {
        int main = s.size();
        int sub = t.size();
        unordered_map<char,int>mpp;
        for(auto it : t){
            mpp[it]++;
        }

        // sliding window comes here

        int left = 0 , right = 0 , minLen = INT_MAX , start = 0;
        while(right<main){
            if(mpp[s[right++]]-- > 0){
                sub--;
            }
            while(sub==0){
                if(right-left<minLen){
                    start = left;
                    minLen = right - left;
                }
                if (++mpp[s[left++]] > 0) {
                    sub++;
                }

            }
        }
        return minLen == INT_MAX ? "" : s.substr(start,minLen);
    }
};