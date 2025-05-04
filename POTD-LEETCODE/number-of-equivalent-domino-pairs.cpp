class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            unordered_map<int, int> mpp;
            int count = 0;
    
            for (const auto& domino : dominoes) {
                int a = domino[0];
                int b = domino[1];
                int key = a < b ? a * 10 + b : b * 10 + a;
    
                count += mpp[key];
                mpp[key]++;
            }
    
            return count;
        }
    };
    