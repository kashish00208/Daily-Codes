 class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            vector<int>result;
            if (!root) return result;
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                int size = q.size();
                for(int i=0;i<size;i++){
                    TreeNode*temp = q.front();
                    q.pop();
                    if(i==size-1)result.push_back(temp->val);
                    if(temp->left)q.push(temp->left);
                    if(temp->right)q.push(temp->right);
                }
            }
            return result;
        }
    };