class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0 , left = 0 , bottom = n-1 , right = n-1 ,  ans = 1;
        vector<vector<int>> mat(n, vector<int>(n));
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                mat[top][i] = ans;
                ans++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                mat[i][right] = ans;
                ans++;
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    mat[bottom][i] = ans;
                    ans++;
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                   mat[i][left] = ans;
                    ans++;
                }
                left++;
            }
        }
        return mat;
    }
};