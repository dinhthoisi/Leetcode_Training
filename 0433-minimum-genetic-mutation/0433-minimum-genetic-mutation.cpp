class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // mỗi gene là một đỉnh, 2 gene có cạnh nếu có một mutation giữa chúng 
        // tìm đường đi ngắn nhất từ gene start đến gene end nếu có dùng bfs và queue 

        // xây dựng graph 
        int L = bank.size(); // số lượng gene trong banks 
         
        // endGene ko có trong banks
        // nếu ko có tức là no mutation return -1
        unordered_set<string> s; 
        for(int i = 0; i < L; i++){
            s.insert(bank[i]);
        }
        if(s.find(endGene) == s.end()) return -1; 
        
        // rồi có được số lượng đỉnh trong graph rồi, xây dựng danh sách kề thôi 
        // xây dựng danh sách kề cho 2 đỉnh startGene và endGene ~ endGene sẽ luôn có trong banks 
        unordered_map<string,unordered_set<string>> adj_list;
        for(int i = 0; i < L; i++){
            int count = 0;
            int count_end = 0;
            for(int j = 0; j < 8; j++){
                if(startGene[j] != bank[i][j]) count++; 
                if(endGene[j] != bank[i][j]) count_end++;
            }
            if(count == 1) {
                adj_list[startGene].insert(bank[i]);
                adj_list[bank[i]].insert(startGene);
            }
            if(count_end == 1){
                adj_list[endGene].insert(bank[i]);
                adj_list[bank[i]].insert(endGene);
            } 
        }
        // xây dựng danh sách kề cho các đỉnh còn lại từ bank (ko trùng startGene và endGene) 
        for(int i = 0; i < L; i++){
            for(int j = 0; j < L; j++){
                if(i!=j){
                    int count = 0; 
                    for(int k = 0; k < 8; k++){
                        if(bank[i][k] != bank[j][k]) count++;
                    }
                    if(count == 1){
                        adj_list[bank[i]].insert(bank[j]);
                        adj_list[bank[j]].insert(bank[i]);
                    }
                }
            }
        }
        // rồi danh sách kề hoàn thiện; h đến bfs và xài queue thôi 
        // xài bfs và queue như thế nào đây ? 
        // đầu tiên là phải có map distance : distance[i] khoản cách từ startGene đến i 
        unordered_map<string,int> distance; 
        distance[startGene] = 0;
        // khởi tạo distance[i] = -1 khi i không phải là startGene 
        for(auto i: adj_list){
            if(i.first != startGene)
                distance[i.first] = -1;
        }
        // code đang bị vòng lặp vô hạn , tại sao lại bị vô hạn nhỉ ?? phải xét thêm đỉnh nào đã visited rồi 
        queue<string> g;
        unordered_set<string> visited;
        g.push(startGene);
        visited.insert(startGene);
        while(g.empty() == false){
            string e = g.front();
            // update distance cho các đỉnh kề e
            for(auto i: adj_list[e]){ 
                // update distance sai rồi ! sai ở đâu ?
                // khi nào thì update distance cho i ? 
                 
                if(visited.find(i) == visited.end()){ // khi i chưa được visit 
                    //if(distance[i] == -1)
                    //    distance[i] = distance[e]++;
                    //else 
                    //    distance[i] = min(distance[i],distance[e] + 1);
                    g.push(i);
                    if(distance[i] == -1)
                        distance[i] = distance[e] + 1; 
                    visited.insert(i);
                }      
            }
            g.pop();
        }
        // debug bằng cách in ra danh sách kề 
        // adj_list : string -> unordered_set<string> 
        // làm sao để in ra 1 unordered_map ??
        // unordered_map<string,unordered_set<string>> adj_list;
        for(auto i: adj_list){
            unordered_set<string>::iterator itr;
            cout << "distance[" << i.first << "] = " << distance[i.first] << endl; 
            cout << i.first << " : ";
            for (itr = i.second.begin(); itr != i.second.end(); itr++)
                cout << (*itr) << " ";
            cout << endl << endl;
        }
        // in ra visited 
        // unordered_set<string> visited; 
        cout << "visited: ";
        for(auto i: visited){
            cout << i << " ";
        }
        if(visited.find(endGene) == visited.end()) return -1;
        return distance[endGene];
    }
};