class Solution {
public:
    int no_islands = 0;
    int numIslands(vector<vector<char>>& grid) {
        int L = grid.size();
        int H = grid[0].size();

        vector<vector<int>> visited(L,vector<int>(H));
        for(int i = 0; i < L; i++){
            for(int j = 0; j < H; j++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    no_islands++;
                    dfs(grid,i,j,visited);
                }
            }
        }

        return no_islands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& visited){
        visited[i][j] = 1;
        if(i >= 1 && visited[i-1][j] == 0 && grid[i-1][j] == '1') dfs(grid,i-1,j,visited);
        if(j >= 1 && visited[i][j-1] == 0 && grid[i][j-1] == '1') dfs(grid,i,j-1,visited);
        if(i+1 < grid.size() && visited[i+1][j] == 0 && grid[i+1][j] == '1') dfs(grid,i+1,j,visited);
        if(j+1 < grid[0].size() && visited[i][j+1] == 0 && grid[i][j+1] == '1') dfs(grid,i,j+1,visited); 
    }
};