

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root)return s;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode * temp=q.front();
            q.pop();
            if(temp==NULL)s.append("null,");
            else{
                s.append(to_string(temp->val)+",");
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return nullptr;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        queue<TreeNode*>q;
        int a=stoi(str);
        TreeNode * root= new TreeNode(a);
        q.push(root);

        while(!q.empty()){
            TreeNode * temp= q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "null")
                temp->left = nullptr;
            else{
                TreeNode * leftNode = new TreeNode(stoi(str));
                temp->left= leftNode;
                q.push(leftNode);
            }
            getline(s, str, ',');
            if(str == "null")
                temp->right = nullptr;
            else{
                TreeNode * rNode = new TreeNode(stoi(str));
                temp->right= rNode;
                q.push(rNode);
            }
        }
        return root;
    }
};