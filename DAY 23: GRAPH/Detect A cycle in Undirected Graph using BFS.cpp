

class Solution {
  public:
    bool bfs(int node, vector<int>adj[] , vector<int>&vis){
        vis[node]=1;
        queue<pair<int, int>>q;
        
        q.push({node, -1});
        
        while(!q.empty()){
            int first=q.front().first;
            int parent=q.front().second;
            
            q.pop();
            
            for(auto it: adj[first]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it, first});
                }else{
                    if(parent!=it){
                        return true;
                    }
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
               if(bfs(i , adj , vis ))return true;
           }
       }
       return false;
    }
};