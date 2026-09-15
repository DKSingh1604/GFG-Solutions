class Solution {
	public:
	vector<string> ans;
	
	void solve(int n, int i, int j, vector<vector<int>> &maze, vector<vector<int>> &vis, string path){
	    
	    //base case
	    if(i == n-1 && j == n-1){
	        ans.push_back(path);
	        return;
	    }
	    
	    //recursive conditions
	    //downward - [i+1][j]
	    if(i+1<n && !vis[i+1][j] && maze[i+1][j]){
	        vis[i][j] = 1;
	        solve(n, i+1, j, maze, vis, path + 'D');
	        vis[i][j] = 0;
	    }
	    
	    //left
	    if(j-1>=0 && !vis[i][j-1] && maze[i][j-1]){
	        vis[i][j] = 1;
	        solve(n, i, j-1, maze, vis, path + 'L');
	        vis[i][j] = 0;
	    }
	    
	    //right
	    if(j+1 < n && !vis[i][j+1] && maze[i][j+1]){
	        vis[i][j] = 1;
	        solve(n, i, j+1, maze, vis, path + 'R');
	        vis[i][j] = 0;
	    }
	    
	   //upward
	   if(i-1 >= 0 && !vis[i-1][j] && maze[i-1][j]){
	        vis[i][j] = 1;
	        solve(n, i-1, j, maze, vis, path + 'U');
	        vis[i][j] = 0;
	    }
	    
	}
	vector<string> ratInMaze(vector<vector<int>> & maze) {
		// code here
		if(!maze[0][0]){
		    return {};
		}
		int n = maze.size();
		vector<vector<int>> vis(n, vector<int>(n, 0));
		string path = "";
		solve(n, 0, 0, maze, vis, path);
		return ans;
	}
};
