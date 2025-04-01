class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            long long DP[1000000] = {};
            int n = questions.size();
            for(int i=n-1;i>=0;--i){
                DP[i] = max(questions[i][0] + DP[questions[i][1] + i + 1], DP[i + 1]);
            }
            return DP[0];
        }
    };
    //SOLVED USING DP 