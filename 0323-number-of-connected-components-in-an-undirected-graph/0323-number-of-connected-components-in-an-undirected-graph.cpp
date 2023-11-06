class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // số lượng các cạnh trong đồ thị
        int L = edges.size();
        // danh sách kề : các đỉnh kề với a được lưu hết vào một set
        map<int,set<int>> adj_list;
        for(int i = 0; i < L; i++){
            adj_list[edges[i][0]].insert(edges[i][1]);
            adj_list[edges[i][1]].insert(edges[i][0]);
        }
        // số lượng các cc
        int count = 0;
        int count_not_isolated_nodes = 0;
        // các đỉnh đã visited 
        set<int> visited;
        // duyệt qua các đỉnh trong danh sách kề
        for(auto i: adj_list){
            count_not_isolated_nodes++;
            // nếu i.first chưa có trong visited thì thêm i vào trong visited 
            // nếu i.first có trong visited rồi thì sao ?
            if(visited.find(i.first) == visited.end()){
                count++;
                visited.insert(i.first);
                for(auto j: i.second){
                    dfs(visited,adj_list,j);
                }    
            }     
        }

        return count + n - count_not_isolated_nodes;
    }
    void dfs(set<int>& visited,map<int,set<int>>& adj_list, int j){
        if(visited.find(j) == visited.end()){
            visited.insert(j);
            for(auto k: adj_list[j]){
                dfs(visited,adj_list,k);
            }
        }    
    }
};
/*
    làm sao để tìm số lượng các connected components 
    sau đó lưu chúng lại ? 
    ý tưởng là gì ? khi duyệt tới một node a mà a không có trong visited thì 
    tăng count lên, sau đó update visited với các node trong danh sách kề của a
    * này là bài toán dfs cơ bản mà ! hỏi Đô là bị la đấy 
*/
/*
        int count_not_isolated_nodes = 0;
        set<int> visited;
        // số lượng các đỉnh trong graph có rồi 
        for(auto i: adj_list){
            count_not_isolated_nodes++;
            if(visited.find(i.first) == visited.end()){
                count++;
                visited.insert(i.first);
            }
            for(auto j: i.second)
                visited.insert(j);
        }
        return count + (n - count_not_isolated_nodes);
*/