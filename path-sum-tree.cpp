class Solution {
    public:
        bool check(TreeNode* root, int sum ,int targetSum){
            if(!root){
                return false;
            }
            sum += root->val;
            if(!root->left && !root->right){
                if(sum == targetSum){
                    return true;
                }
                return false;
            }
            bool left = check(root->left,sum,targetSum);
            bool right = check(root->right,sum,targetSum);
            return left || right;
        }
        bool hasPathSum(TreeNode* root, int targetSum) {
            if(!root){
                return false;
            }
            return check(root,0,targetSum);
        }
    };