

class Solution {
public:
    int func(TreeNode* root, int & ans){
        if(root==NULL)return 0;
        int l=func(root->left, ans);
        int r=func(root->right, ans);
        ans=max(ans, root->val+l+r);
        return (max(l, r)+root->val);
    }
    int maxPathSum(TreeNode* root) {
        int ans=0;
        func(root, ans);
        return ans;
    }
};