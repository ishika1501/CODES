TREE :hierarchical data structure 

non linear structure :
linear structure:

root :
childre:
leaf node:
sub-tree:
Ancestor : 

TYPES OF BINARY TREE:
1.full binary tree: wither has 2 or 0 children
2.complete binary tree: all level are filled except the last level ,the last level has all nodes as left has as possible 
3.perfect binary tree: all the leaf nodes are at the same level 
4.Balanced binary tree: left and right have diff of 1
5.Degenerate tree: where each parent node has only one child


Represenation of Binary tree

struct node {
    int data;
    struct Node* left;
    struct Node* right;

    node(int val){
        data=val;
        left=right=null;
    }
}

main(){
    struct node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
}