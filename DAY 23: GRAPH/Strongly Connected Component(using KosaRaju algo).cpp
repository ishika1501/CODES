
1. perform the topo sort on the nodes of the graph that is o(N);
2. Transpose the graph (that is reverse the connection) --> O(N+E);
3. do the DFS call on the nodes -->O(N+E);

space complexity :  O(N+E) FOR TRANSPOSE GRAPH + 0(N) FOR STACK + 0(N) FOR STORING VIS ARRAY


class Solution
{
	public:
	
	void dfs(int node, vector<int>&vis , stack<int>&st , vector<vector<int>>& adj){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,st,adj);
	        }
	    }
	    st.push(node);
	}
	
	void revofdfs(int node, vector<int>& vis, vector<vector<int>>& transpose) {
        vis[node] = true;
        for (auto it : transpose[node]) {
            if (!vis[it]) {
                revofdfs(it, vis, transpose);
            }
        }
    }
	
	
    int kosaraju(int V, vector<vector<int>>& adj){
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0 ;i<V ;i++){
            if(!vis[i]){
                dfs(i , vis, st , adj);
            }
        }
        
        vector<vector<int>> transpose(V);
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                transpose[it].push_back(i);
            }
        }
        
        int count = 0;
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            if (!vis[top]) {
                revofdfs(top, vis, transpose);
                count++;
            }
        }
        return count;
        
    }
};
