same logic as topo sort .
instead of storing the node we are just countingthe node 
if the count is same as the V , that mean there is no cycle 
because topo work for DAG .



class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int>indeg(V,0);
	    for(int i=0 ;i<V; i++){
	        for(auto it :adj[i]){
	            indeg[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0 ;i<V ;i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    
	    //vector<int>ans;
	    int count=0;
	    while(!q.empty()){
	        int n = q.front();
	        q.pop();
	        //ans.push_back(n);
	        count++;
	        for(auto it:adj[n]){
	            indeg[it]--;
	            if(indeg[it]==0)q.push(it);
	        }
	    }
	   if(count==V) return false;
	    else return true;
    }
};