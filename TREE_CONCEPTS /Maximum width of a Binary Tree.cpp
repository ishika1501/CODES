
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=0;

        // Create a queue to perform level-order
        // traversal, where each element is a pair
        // of TreeNode* and its position in the level
        queue<pair<TreeNode*, int>> q;
        // Push the root node and its
        // position (0) into the queue
        q.push({root, 0});

        while(!q.empty()){
            int size=q.size();

            int start=q.front().second;
            int end=q.back().second;

            ans=max(ans, end-start+1);

            while(size--){
                int idx = q.front().second - end;
                TreeNode * node=q.front().first;
                q.pop();

                if(node->left) {
                    q.push({node->left, 2 * idx + 1});
                }
                    
                if(node->right) {
                    q.push({node->right, 2 * idx + 2});
                }
            }
        }
        return ans;
    }
};