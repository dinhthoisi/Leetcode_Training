class Solution {
public:
    vector<vector<vector<int>>> islands1;  // lưu hết các islands trong grid1 lại
    vector<vector<vector<int>>> islands2;  // lưu hết các islands trong grid2 lại
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int L = grid1.size();
        int H = grid1[0].size();
        vector<vector<int>> visited1(L,vector<int>(H));
        for(int i = 0; i < L; i++){
            for(int j = 0; j < H; j++){
                if(visited1[i][j] == 0 && grid1[i][j] == 1){
                    vector<vector<int>> seperate_island;               
                    seperate_island.push_back({i,j});
                    dfs(grid1,i,j,visited1,seperate_island);
                    islands1.push_back(seperate_island);
                }
            }
        }
        // gán id cho mỗi island trong grid 1 
        map<vector<int>,int> u;
        int l1 = islands1.size(); // l1 là số lượng đảo trong grid 1
        // loop over all islands in grid 1
        for(int i = 0; i < l1; i++){
            // loop over all cell in island i th in grid 1 
            for(int j = 0; j < islands1[i].size(); j++){
                u[islands1[i][j]] = i; // cells thuộc đảo i sẽ có id  là i 
            }
        }
        
        L = grid2.size();
        H = grid2[0].size();
        vector<vector<int>> visited2(L,vector<int>(H));
        for(int i = 0; i < L; i++){
            for(int j = 0; j < H; j++){
                if(visited2[i][j] == 0 && grid2[i][j] == 1){
                    vector<vector<int>> seperate_island2;               
                    seperate_island2.push_back({i,j});
                    dfs(grid2,i,j,visited2,seperate_island2);
                    islands2.push_back(seperate_island2);
                }
            }
        }

        // compare islands1 and islands2 
        int l2 = islands2.size(); // l2 là số lượng đảo trong grid 2 
        int no_sub_islands = 0;   // output cần tìm 

        // consider all islands in grid 2 
        for(int m = 0; m < l2; m++){
            int h;
            int check = 0;
            if(grid1[islands2[m][0][0]][islands2[m][0][1]] == 1){
                h = u[islands2[m][0]];
                int k = islands1[h].size();
                // loop over all cells in islands2[m] xem có là subislands của đảo islands1[h] 
                for(int i = 0; i < islands2[m].size(); i++){
                    if(u[islands2[m][i]] == h && grid1[islands2[m][i][0]][islands2[m][i][1]] == 1 ) 
                        check++;
                    // loop over all cells in islands1[h] 
                    /*
                    for(int j = 0; j < k; j++){
                        if(islands2[m][i][0] == islands1[h][j][0] && islands2[m][i][1] == islands1[h][j][1]){
                            check++;
                            break;
                        }
                    }
                    */
                }
                if (check == islands2[m].size()) no_sub_islands++;
            }
        }

        return no_sub_islands;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited,vector<vector<int>>& seperate_island){
        visited[i][j] = 1;
        if(i >= 1 && visited[i-1][j] == 0 && grid[i-1][j] == 1) {
            seperate_island.push_back({i-1,j});
            dfs(grid,i-1,j,visited,seperate_island);
        }
        if(j >= 1 && visited[i][j-1] == 0 && grid[i][j-1] == 1) {
            seperate_island.push_back({i,j-1});
            dfs(grid,i,j-1,visited,seperate_island);
        }
        if(i+1 < grid.size() && visited[i+1][j] == 0 && grid[i+1][j] == 1) {
            seperate_island.push_back({i+1,j});
            dfs(grid,i+1,j,visited,seperate_island);
        }
        if(j+1 < grid[0].size() && visited[i][j+1] == 0 && grid[i][j+1] == 1) {
            seperate_island.push_back({i,j+1});
            dfs(grid,i,j+1,visited,seperate_island); 
        } 
    }
};
