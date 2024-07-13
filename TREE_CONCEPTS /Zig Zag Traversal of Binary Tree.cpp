we are actually having a flag 
that would indicate if that we have to move left to right or roght to left 
and with each traversal we can chnage accordingly 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        bool flag=true;  
        q.push(root);
        
        while(!q.empty()){
            int s=q.size();
            vector<int>row(s);
            for(int i=0 ;i<s ;i++){
                TreeNode * node=q.front();
                q.pop();
                int idx=(flag)?i:(s-i-1);

                row[idx]=node->val;
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            flag=!flag;
            ans.push_back(row);
        }
        return ans;
    }
};