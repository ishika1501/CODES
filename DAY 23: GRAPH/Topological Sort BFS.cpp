
TOPO SORT EXIST ONLY FOR DAG GRAPHS 
IF THERE IS AN EDGE FROM U-->V 
SO U APPEAR BEFORE V

step :
 1. first find all the nodess indegree 
 2. push the node that would have a 0 indegree
 3. pick up one node and push that in ans,
 4. whatever node is there in the adj, retduce its indegree.


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{   
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
	    
	    vector<int>ans;
	    while(!q.empty()){
	        int n = q.front();
	        q.pop();
	        ans.push_back(n);
	        
	        for(auto it:adj[n]){
	            indeg[it]--;
	            if(indeg[it]==0)q.push(it);
	        }
	    }
	    return ans ;
	    
	}
};