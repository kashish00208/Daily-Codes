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
            ans.push_back(root->val);
            get(root->left,ans);
            get(root->right,ans);
        }
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int>ans;
            get(root,ans);
            return ans;
        }
    };
//Iterative approach to solve the problem
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int>ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right){
                st.push(temp->right);
            }
            if(temp->left){
                st.push(temp->left);
            }
        }
        return ans;                          
    }
};
