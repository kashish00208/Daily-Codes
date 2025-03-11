//calculating minimum depth of a binary tree 
 class Solution {
    public:
        int minDepth(TreeNode* root) {
            if(root==NULL)return 0;
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            if(root->left == NULL && root->right == NULL)return 1;
            if(root->left == NULL)return 1 + right;
            if(root->right == NULL)return 1 + left;
            int ans = min(right,left)+1;
            return ans;
        }
    };