

// we have to run the iteration by n-1;
//because the graoph has N nodes, so in the worst case 
//we will take N-1 node to reach the last node from the first 


//HOW TO DETECT THE NEGATIVE CYCLE ?
// the iteration for the Nth time the value will still reduce 
//because mostly at max we need N-1 iteration 


class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V,1e8);
        dist[S]=0;
        
        for(int i=0 ;i<V-1; i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        // idealy this is the end and we can return the dist[] as answer
        // but there is a possibilty of negative cycle 
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u] != 1e8 and dist[u]+wt < dist[v]) {
                return {-1};
            }
        }
        
        return dist;
        
    }
    
};
