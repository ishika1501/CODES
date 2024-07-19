TOPO SORT EXIST ONLY FOR DAG GRAPHS 
IF THERE IS AN EDGE FROM U-->V 
SO U APPEAR BEFORE V


1. we keep on making a dfs traversal
2. and stop when there is no further node, then push that into the stack 

class Solution
{
	public:
	void dfs(int node, vector<int>&vis , stack<int>&st , vector<int>adj[]){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it, vis, st , adj);
	        }
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int>vis(V,0);
	    stack<int>st;
	    
	    for(int i=0 ;i<V; i++){
	        if(!vis[i]){
	            dfs(i , vis, st , adj);
	        }
	    }
	    
	    vector<int>ans;
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};