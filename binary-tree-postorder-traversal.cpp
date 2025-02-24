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
        void get(TreeNode* root,vector<int>&ans){
            if(root==NULL)return;
            get(root->left,ans);
            get(root->right,ans);
            ans.push_back(root->val);
        }
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int>ans;
            get(root,ans);
            return ans;
        }
        };
        //Iterative approach to post order traversal
        vector<int> postorderTraversal(TreeNode* root) {
            if(root==NULL)return{};
            vector<int>ans;
            stack<TreeNode*>st;
            st.push(root);
            while(!st.empty()){
                TreeNode*temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                if(temp->left){
                    st.push(temp->left);
                }
                if(temp->right){
                    st.push(temp->right);
                }
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }