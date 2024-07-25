

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(root==NULL)return 1;
        if(root->left==NULL && root->right==NULL) return 1;
        int lefts=0,rights=0,sum=0;
        
        if(root->left)lefts=root->left->data;
        if(root->right)rights=root->right->data;
        
        if(root->data==(lefts+rights)){
            if(isSumProperty(root->left) && isSumProperty(root->right)){
             return 1;
            }
        }
        return 0;
    }
};