

class Solution {
public:
    bool func(TreeNode * root1,TreeNode *root2){
        
        if(!root1 || !root2)return (root1==root2);
        if(root1->val != root2->val){
            return false;
        }else{
            return(func(root1->left,root2->right) && func(root1->right,root2->left));
        }
    }
    bool isSymmetric(TreeNode* root) {
        return func(root, root);
    }
};