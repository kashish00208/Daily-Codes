class Solution {
    public:
      vector<int> topView(Node *root) {
          queue<pair<Node*,int>>q;
          map<int,int>mpp;
          vector<int>ans;
          q.push({root,0});
          while(!q.empty()){
              auto it = q.front();
              q.pop();
              Node*temp = it.first;
              int line = it.second;
              if(mpp.find(line)==mpp.end()){
                  mpp[line] = temp->data;
              }
              if(temp->left){
                  q.push({temp->left,line-1});
              }
              if(temp->right){
                  q.push({temp->right,line+1});
              }
          }
          for(auto it:mpp){
              ans.push_back(it.second);
          }
          return ans;
      }
  };