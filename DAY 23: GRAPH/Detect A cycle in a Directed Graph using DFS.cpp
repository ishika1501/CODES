
class Solution {
  public:
    bool checkcycle(int node, vector<int> adj[], vector<int>&vis, vector<int>&dfsVis){
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (checkcycle(it, adj, vis, dfsVis)) return true;
            } else if (dfsVis[it] == 1) {
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>dfsVis(V,0);
        
        for(int i=0 ;i<V ;i++){
            if(!vis[i]){
                if(checkcycle(i, adj , vis, dfsVis))return true;
            }
        }
        return false;
    }
};