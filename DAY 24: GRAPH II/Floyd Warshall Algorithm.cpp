


class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
        //just place 1e9 in place of -1 for the sake of just writing
        for(int i=0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == -1) {
                    matrix[i][j] = 1e9;
                }
                if(i==j) matrix[i][j] = 0;
            }
        }
        
        //main algorithm
        for(int via = 0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j = 0; j<n; j++){
                matrix[i][j] = min(matrix[i][j] , matrix[i][via] + matrix[via][j]);
                }
            }
        }
        
        //to detect the negative cycle
        /*
        for(int i=0; i<n; i++){
        if(matrix[i][j] < 0) {
            return {-1};
        }
        }
        
        */
        
        //replace the -1 back in place of 1e9
        for(int i=0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
        
    }
};