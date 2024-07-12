
use stack to push values  and a number ;
if we have number as 1:
    push the valus of that node to preorder 
    increment the int val to 2
    push back to stack with node and number

    if that node has left push the left ;

if that number is 2:
    push the values of that node to inorder
    increment that int val to 3
    push back to stack with node and number 

    if that node has right , push that node and value in the stack;

if that number is 3 :
    push the values of that node to post order 
    


vector<int>PreInPost(TreeNode * root){
    stack<pair<TreeNode* , int>>st;
    st.push_back({root, 1});

    vector<int>pre, in, post;
    if(root==NULL)return;

    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(st.second==1){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->left!=NULLs) st.push({it.first->left,1});
        }else if(it.second==2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->right!=NULL)st.push({it.first->right, 2});
        }else{
            post.push_back(it.first->val);
        }
    }
}


TIME COMPLEXITY : 0(3N)-->in worst case each node is travesed 3 times;
SPACE COMPLEXITY : 3*N 