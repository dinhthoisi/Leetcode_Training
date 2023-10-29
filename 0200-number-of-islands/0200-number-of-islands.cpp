class Solution {
public:
    int no_islands = 0;
    vector<vector<vector<int>>> islands; // lưu hết các islands lại
    int numIslands(vector<vector<char>>& grid) {
        int L = grid.size();
        int H = grid[0].size();

        vector<vector<int>> visited(L,vector<int>(H));
        for(int i = 0; i < L; i++){
            for(int j = 0; j < H; j++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    no_islands++;
                    vector<vector<int>> seperate_island;
                    vector<int> point;
                    point.push_back(i), point.push_back(j);
                    seperate_island.push_back(point);
                    dfs(grid,i,j,visited,seperate_island);
                    islands.push_back(seperate_island);
                }
            }
        }

        int no = islands.size();
        for(int i = 0; i < no; i++){
            cout << "island number " << i + 1 << endl; 
            int len = islands[i].size();
            for(int j = 0; j < len; j++){
                cout << islands[i][j][0] << " " << islands[i][j][1] << endl;
            }
        }

        return no_islands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& visited,vector<vector<int>>& seperate_island){
        visited[i][j] = 1;
        if(i >= 1 && visited[i-1][j] == 0 && grid[i-1][j] == '1') {
            vector<int> point;
            point.push_back(i-1), point.push_back(j);
            seperate_island.push_back(point);
            dfs(grid,i-1,j,visited,seperate_island);
        }
        if(j >= 1 && visited[i][j-1] == 0 && grid[i][j-1] == '1') {
            vector<int> point;
            point.push_back(i), point.push_back(j-1);
            seperate_island.push_back(point);
            dfs(grid,i,j-1,visited,seperate_island);
        }
        if(i+1 < grid.size() && visited[i+1][j] == 0 && grid[i+1][j] == '1') {
            vector<int> point;
            point.push_back(i+1), point.push_back(j);
            seperate_island.push_back(point);
            dfs(grid,i+1,j,visited,seperate_island);
        }
        if(j+1 < grid[0].size() && visited[i][j+1] == 0 && grid[i][j+1] == '1') {
            vector<int> point;
            point.push_back(i), point.push_back(j+1);
            seperate_island.push_back(point);
            dfs(grid,i,j+1,visited,seperate_island); 
        } 
    }
};
/*
    làm sao biết được mỗi island sẽ có các ô nào ?
    lưu các islands vào data structure vector<vector<vector<int>>> islands
    như example 2, islands sẽ là :
    islands[0] = [0,0] [0,1] [1,0] [1,1]
        islands[0][0] = [0,0]
            islands[0][0][0] = 0
            islands[0][0][1] = 0
        islands[0][1] = [0,1]
        islands[0][2] = [1,0]
        islands[0][3] = [1,1]            
    islands[1] = [2,2] 
    islands[2] = [3,3] [3,4] 
*/







