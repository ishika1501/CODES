
class Solution {
  public:
    void helper (Node* root,vector<int>&ans, vector<vector<int>>&res ){
        if(root == NULL) return;
          if(root->left == NULL && root->right == NULL){
              ans.push_back(root->data);
              res.push_back(ans);
              ans.pop_back();
              return;
          }
          ans.push_back(root->data);
          helper(root->left, ans, res);
          helper(root->right, ans, res);
          ans.pop_back();
          return;
        }
    vector<vector<int>> Paths(Node* root) {
       vector<vector<int>>res;
       vector<int>ds;
       helper(root, ds, res);
       return res;
    }
};