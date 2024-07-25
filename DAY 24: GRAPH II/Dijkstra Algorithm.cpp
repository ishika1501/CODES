

//it fails when the edge is negative 
//it will keep on running tif there is a negative cycle 

// it work in DAG , otherwise change to DAG 

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
       vector<bool>vis(V, false);
       vector<int>dist(V, 1e9);
       
       pq.push({0, S});
       dist[S]=0;
       
       while(!pq.empty()){
           int node=pq.top().second;
           pq.pop();
           
           if(vis[node]) continue;
           vis[node] = true;
           
           for(auto &v: adj[node]){
               int child=v[0], wt=v[1];
               if(dist[node]+ wt < dist[child] ){
                   dist[child] = dist[node] + wt;
                   pq.push({dist[child], child});
               }
           }
            
       }
       return dist;
       
    }
};
