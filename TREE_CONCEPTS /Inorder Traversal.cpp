
//RECUSSIVE 
inorder --> let , root, right 

void inorder(TreeNode * node, vector<int>v){
    if(root==NULL)return ;

    inorder(node->left, v);
    ans.push_back(root->val);
    inorder(node->right, v);
    
}

//ITERTIVE:

vector<int> inorderTraversal(TreeNode* root) {
         vector<int> ans;
        TreeNode* node = root;
        stack<TreeNode*> st;

        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                if (st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
}
