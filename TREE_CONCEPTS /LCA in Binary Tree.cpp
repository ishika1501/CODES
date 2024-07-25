

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==NULL || root==p || root==q)return root;

        // TreeNode* left= lowestCommonAncestor(root->left, p, q);
        // TreeNode* right=lowestCommonAncestor(root->right, p, q);

        // if(left==NULL)return right;
        // if(right==NULL)return left;

        // else return root;

        std::stack<TreeNode*> stack;
        stack.push(root);

        // Map for parent pointers
        std::unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;

        // Iterate until we find both nodes p and q
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* node = stack.top();
            stack.pop();

            // If left child exists, add to stack and record parent
            if (node->left) {
                parent[node->left] = node;
                stack.push(node->left);
            }

            // If right child exists, add to stack and record parent
            if (node->right) {
                parent[node->right] = node;
                stack.push(node->right);
            }
        }

        // Ancestors set for node p
        std::unordered_set<TreeNode*> ancestors;

        // Process all ancestors for node p using parent pointers
        while (p != nullptr) {
            ancestors.insert(p);
            p = parent[p];
        }

        // The first ancestor of q which appears in
        // p's ancestor set is their lowest common ancestor
        while (ancestors.find(q) == ancestors.end()) {
            q = parent[q];
        }

        return q;

    }
};