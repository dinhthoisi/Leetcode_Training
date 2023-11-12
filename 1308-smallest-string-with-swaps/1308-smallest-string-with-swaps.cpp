class Solution {
public:
    // các đỉnh đã visited 
    set<int> visited;
    // danh sách kề : các đỉnh kề với a được lưu hết vào một set
    map<int,set<int>> adj_list;

    string smallestStringWithSwaps(string s, vector<vector<int>>& edges) {
        int n = s.size();
        // số lượng các cạnh trong đồ thị
        int L = edges.size();
        for(int i = 0; i < L; i++){
            adj_list[edges[i][0]].insert(edges[i][1]);
            adj_list[edges[i][1]].insert(edges[i][0]);
        }
        // duyệt qua các đỉnh trong danh sách kề
        for(int i = 0; i < n; i++){
            if(visited.find(i) == visited.end()){
                //visited.insert(i);
                vector<char> characters;
                vector<int> indices;
                dfs(s,i,characters,indices);
                // Sort the list of characters and indices
                sort(characters.begin(), characters.end());
                sort(indices.begin(), indices.end());

                // Store the sorted characters corresponding to the index
                for (int index = 0; index < characters.size(); index++) {
                    s[indices[index]] = characters[index];
                }
            }     
        }

        return s;
    }

    void dfs(string& s,int j,vector<char>& characters,vector<int>& indices){
        if(visited.find(j) == visited.end()){
            characters.push_back(s[j]);
            indices.push_back(j);
            visited.insert(j);
            for(auto k: adj_list[j]){
                dfs(s,k,characters,indices);
            }
        }    
    }
};
