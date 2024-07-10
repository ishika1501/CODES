
postorder : left , right , root ;

void PostOrder(node){
    if(node==NULL)return;

    postorder(node->left);
    postorde(node->right);
    ans.push_back(node->val);
}