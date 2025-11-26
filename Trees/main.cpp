#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
void levelorderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

void iterativePre(TreeNode *root)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        cout << node->data<<" ";
        if (node->right!=nullptr)
        {
            st.push(node->right);
        }
        if (node->left!=nullptr)
        {
            st.push(node->left);
        }
        
    }
}


//ROOT to leaf node path in binary tree
bool rootToNode(TreeNode*root,int x , vector<int>nums){
    if(root==NULL)return false;
    nums.push_back(root->data);

    if(root->data){
        return true;
    }

    if(rootToNode(root->left,x,nums)||rootToNode(root->right,x,nums)){
        return true;
    }

    nums.pop_back();
    return false;
}


vector<int> postOrderdr2(TreeNode*root){
    stack<TreeNode*>st1;
    stack<TreeNode*>st2;
    st1.push(root);
    while(!st1.empty()){
        TreeNode*node = st1.top();
        st2.push(node);
        if(node->left){
            st1.push(node->left);
        }
        if(node->right){
            st2.push(node->right);
        }
    }
    vector<int>ans;
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

int maxDepth(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    int ans =  max(left,right)+1;
    return ans;
}

int height(TreeNode*root){
    if(root==NULL)return -1;

    int left = height(root->left);
    if(left==-1)return -1;

    int right = height(root->right);
    if(right==-1)return -1;

    if((right-left)>1)return -1;

    int ans = max(left,right)+1;

    return ans;

}

int check(TreeNode*root,int &sum){
    if(root==NULL)return 0;
    int left = max(0,check(root->left,sum));
    int right = max(0,check(root->right,sum));
}

int maxPath(TreeNode*root){
    int sum = INT_MIN;
    check(root,sum);
    return sum;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(8);
    int ans = height(root);

    if(ans){
        cout<<"Tree is balanced "<<endl;
    }else{
        cout<<"Tree is not balanced"<<endl;
    }
    return 0;
}