

class Solution {
public:
    int cnt=0;
    int countNodes(TreeNode* root) {
        if (root == NULL) return cnt;
        cnt++;  
        countNodes(root->left);
        countNodes(root->right);
        return cnt;
    }
};