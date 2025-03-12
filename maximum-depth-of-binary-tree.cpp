/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(!root)return{};
            int ans = 0;
            queue<TreeNode*>q;
            q.push(root);
            q.push(NULL);
            while(!q.empty()){
                TreeNode*temp = q.front();
                q.pop();
                if(temp==NULL){
                    ans++;
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }else{
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                }
            }
            return ans;
        }
    };

    //recursive approach 
    class Solution {
        public:
            int maxDepth(TreeNode* root) {
                if (root==NULL)return 0;
                int left = maxDepth(root->left);
                int right = maxDepth(root->right);
                int ans = max(left,right)+1;
                return ans;
            }
        };
    