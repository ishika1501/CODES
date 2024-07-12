

class Solution {
public:

    int func(TreeNode* node, int & dia){
        if(node==NULL)return 0 ;
        int l=func(node->left , dia);
        int r=func(node->right, dia);
        dia=max(dia, l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        func(root, dia);
        return dia;
    }
};