class Solution {
public:
    vector<int>generateRows(int row){
        long long ans = 1;
        vector<int>temp;
        temp.push_back(ans);
        for(int col=1;col<row;col++){
            ans *= (row-col);
            ans /= col;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>answer;
        for(int i=1;i<=numRows;i++){
            vector<int>ans = generateRows(i);
            answer.push_back(ans);
        }
        return answer;
    }
};