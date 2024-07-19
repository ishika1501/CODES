class Solution {
  public:
    bool dfs(int node, vector<int>adj[], int parent , vector<int>&vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,node,vis))return true;
            }else{
                if(parent!=it){
                    return true;
                }
            }
        }
        return false;
    }
    
    // if the graph is not connected we have to check for the cases of each node
    bool isCycle(int V, vector<int> adj[]) {
       vector<int>vis(V, 0);
       for(int i=0 ;i<V; i++){
           if(!vis[i]){
               if(dfs(i , adj, -1 ,vis))return true;
           }
       }
       return false;
    }
};