class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // lưu các connected components vào gì đây ? 
        map<int,set<int>> cc;

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
        int cc_index = 0; // used for updated cc
        for(auto i: adj_list){
            count_not_isolated_nodes++;
            // nếu i.first chưa có trong visited thì thêm i vào trong visited 
            // rồi dfs với các node trong danh sách kề của i.first
            if(visited.find(i.first) == visited.end()){
                // mỗi lần tăng count lên là mình đã qua 1 cc mới 
                set<int> new_cc;
                count++;
                visited.insert(i.first);
                new_cc.insert(i.first);
                for(auto j: i.second){
                    dfs(visited,adj_list,j,new_cc);
                }
                cc[cc_index] = new_cc; 
                cc_index++;    
            }     
        }

        // in cc ra kiểm tra coi code đúng ko 
        
        for(auto k: cc){
            cout << k.first << ": "; 
            for(auto h: k.second) 
                cout << h << " ";
            cout << endl;
        }
        

        return count + n - count_not_isolated_nodes;
    }
    void dfs(set<int>& visited,map<int,set<int>>& adj_list, int j, set<int>& new_cc){
        if(visited.find(j) == visited.end()){
            visited.insert(j);
            new_cc.insert(j);
            for(auto k: adj_list[j]){
                dfs(visited,adj_list,k, new_cc);
            }
        }    
    }
};
/*
    okie, viết xong dfs rồi thì tìm cách lưu các connected components lại 
    vd đầu tiên thì mình có 2 cc là 0, 1, 2 và 3, 4 
    vd thứ hai thì mình chỉ có 1 cc là 0, 1, 2, 3, 4 
    lưu mỗi cc vào một cái set có vẻ ổn 
*/