


class Solution {
public:

    TreeNode* construct(vector<int>& in, int inStart, int inEnd, vector<int>& post, int postStart, int postEnd, unordered_map<int, int>& ump) {
        if(inStart > inEnd || postStart > postEnd) return NULL;
        TreeNode* root = new TreeNode(post[postEnd]);

        int in_ind = ump[root -> val];
        int ele_left = in_ind - inStart;
        root -> left = construct(in, inStart, in_ind - 1, post, postStart, postStart + ele_left - 1, ump);

        root -> right = construct(in, in_ind + 1, inEnd, post, postStart + ele_left, postEnd - 1, ump);

        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int,int>ump;
        for(int i=0;i<in.size();i++) ump[in[i]] = i;
        return construct(in, 0, in.size()-1, post, 0, post.size()-1, ump);
    }
};