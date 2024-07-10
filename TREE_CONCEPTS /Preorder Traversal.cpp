//RECUSSIVE :

preorder--> root, left , right;


void preorder(TreeNode *node, vector<int>& ans) {
    if (node == NULL) return;

    ans.push_back(node->val);
    preorder(node->left, ans);
    preorder(node->right, ans);
}

//ITERRATIVE APPROACH :

using STACK :
put the root 
put the right --->because stack id LIFO 
put left   


vector<int>preorder(TreeNode *root){
    vector<int>ans;
    if(root==NULL)return ans;
    
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        int root=st.pop();
        st.pop();

        ans.push_back(root->val);
        if(root->right !=NULL){
            st.push(root->right);
        }
        if(root->left!=NULL){
            st.push(root->left)
        }
    }
    return ans;

}


