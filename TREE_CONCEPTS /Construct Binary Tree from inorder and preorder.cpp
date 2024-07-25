
class Solution {
public:
    void * build(vector<int>preorder, vector<int>postorder, int idx, int left , int right){
        if(left>right)return NULL;
        int pivot=left;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootidx=0;
        return function(preorder, inorder, rootidx, 0 , inorder.size()-1);
    }
};