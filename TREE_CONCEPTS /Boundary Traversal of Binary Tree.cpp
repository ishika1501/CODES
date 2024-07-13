

1.we can take left boundary 

2.then take the leaf node

3.then take the right boundary in the reverse direction 


void addLeftBoundary(Node* root, vector<int>&res){
    Node* curr=root->left;
    while(curr){
        if(!isLeaf(curr))res.push_back(cur->data);
        if(cur->left)cu->left;
        else curr->right;
    }
}

void addRightBoundary(Node * root, vector<int>& res){
    Node* curr=root->right;
    vector<int>temp;
    while(curr){
        if(isLeaf(curr))tmp.push_back(curr->data);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
    }

    for(int i=temp.size(); i>=0 ; i--){
        res.puhs_back(tmp[i]);
    }
}

void addLeaves(Node* root, vector<int>& res){
    if(isLeaf(root)){
        res.puhs_back(root->data);
        return;
    }
    if(root->left)addLeaves(root->left, res);
    if(root->right)addLeaves(root->right, res);
}


vector<int>printBoundary(Node* root){
    vector<int>ans;
    if(!root)return res;
    if(!isLeaf(root))res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}
