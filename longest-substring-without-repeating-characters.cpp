//Brute force approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        int count = 0;
        unordered_set<int>ans;
        for(int i=0;i<s.length();i++){
            if(ans.count(s[i])==0){
                ans.insert(s[i]);
                maxi = max(maxi,i-count+1);
            }
            else{
                while(ans.count(s[i])){
                    ans.erase(s[count]);
                    count++;
                }
                ans.insert(s[i]);
            }
        }
        return maxi;
    }
};

//Optimal approach Using sliding window technique
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(256,-1);
        int len = 0;
        int i = 0 , j = 0;
        while(j<s.size()){
            if(mpp[s[j]] != -1){
                i = max(i, mpp[s[j]] + 1);
            }
            mpp[s[j]] = j;
            len = max(len,j-i+1);
            j++;
        }
        return len;
    }
};

