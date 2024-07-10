     1
    / \
    2  3
   /\  /\
  4  5 6 7


solution :
we can take a queue/stack  to store the 

vector<vector<int>>levelOrder(TreeNode * root){
    vector<vector<int>>ans;
    if(root==NULL)return ans;

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0 ;i<n ;i++){
            TreeNode * node=q.front();
            q.pop();
            if(node->left!=NULL)q.push(node->left);
            if(node->right!=NULL)q.push(node->right);
            level.push_back(node->val);
        }

        ans.push_back(level);
    }

    return ans;
}