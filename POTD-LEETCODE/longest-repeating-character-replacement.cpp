class Solution {
public:
    int characterReplacement(string s, int k) {
        int right = 0 , left = 0 , ans = 0 , maxf = 0;
        unordered_map<char,int>hash;
        while(right<s.size()){
            hash[s[right]]++;
            maxf = max(maxf,hash[s[right]]);
            if((right-left+1)-maxf>k){
                hash[s[left]]--;
                left++;
            }
            ans = max(ans,right-left+1); 
            right++;
        }
        return ans;
    }
};