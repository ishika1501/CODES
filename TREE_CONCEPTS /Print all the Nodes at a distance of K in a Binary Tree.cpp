
class Solution {
public:
    vector<int>ans;
    unordered_map<TreeNode* , TreeNode*>parents;
    set<TreeNode*>st;
    void findparents(TreeNode* node){
        if(node==NULL)return;
        if(node->left){
            parents[node->left] = node;
            findparents(node->left);
        }
        if(node->right){
            parents[node->right] = node;
            findparents(node->right);
        }
    }
    void dfs(TreeNode* root, int k){
        if(root==NULL)return ;
        if(st.count(root)>0)return ;
        st.insert(root);

        if(k==0){
            ans.push_back(root->val);
            return;
        }
        dfs(root->left, k - 1);
        dfs(root->right, k - 1);
        dfs(parents[root], k - 1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL)return ans;
        findparents(root);
        dfs(target, k);
        return ans;
    }
};