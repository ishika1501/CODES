class Solution {
public:
    Node* dfs(Node* curr,unordered_map<Node*,Node*>& mp){
        Node* clone =new Node(curr->val);
        mp[curr]=clone;
        for(auto it: curr->neighbors){
            if(mp.find(it)==mp.end()){
                (clone->neighbors).push_back(dfs(it, mp));
            }else{
                (clone->neighbors).push_back(mp[it]);
            }
        }
        return clone;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node* , Node*>mp;
        if(node==NULL)return NULL;
        if(node->neighbors.size()==0){
            Node* temp= new Node(node->val);
            return temp;
        }

        return dfs(node, mp);
    }
};

