
To find that we can use both recussion and level oder 
level order will have a overhead of extra space where as 
the recuession has a overhead if the tree is skewed 

mostly we see lesser skewed trees so will go with recussion 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};