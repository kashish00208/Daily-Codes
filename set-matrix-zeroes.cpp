class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int>Row; 
        unordered_set<int>Col; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    Row.insert(i);
                    Col.insert(j);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Row.count(i)>0 || Col.count(j)>0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};