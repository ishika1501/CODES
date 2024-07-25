class Solution {
  public:
    int ans=0;
    
    void downNode(Node* root,Node* block,int bt){
        if(!root or root == block){
            return;
        }
        ans = max(ans,bt);
        downNode(root->left,block,bt+1);
        downNode(root->right,block,bt+1);
    }
    int findNode(Node* root , int target ){
        if(!root){
            return -1;
        }
        if(root->data == target){
            downNode(root,NULL,0);
            return 1;
        }
        int l = findNode(root->left,target);
        if(l != -1){
            downNode(root,root->left,l);
            return l + 1;
        }
        int r = findNode(root->right,target);
        if(r != -1){
            downNode(root,root->right,r);
            return r + 1;
        }
    }
    int minTime(Node* root, int target) {
        findNode(root, target);
        return ans;
    }
};