class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,set<int>> umap;
        int L = adjacentPairs.size();
        for(int i = 0; i < L; i++){
            umap[adjacentPairs[i][0]].insert(adjacentPairs[i][1]);
            umap[adjacentPairs[i][1]].insert(adjacentPairs[i][0]);
        }
        // L + 1 đỉnh 
        vector<int> res;
        int begin; // đỉnh bắt đầu
        for(auto i: umap){
            if(i.second.size() == 1){
                begin = i.first;
                break;
            }
        }
        set<int> visited;
        res.push_back(begin);
        visited.insert(begin);
        // dfs từ begin để update res 
        dfs(begin,umap,visited,res);

        return res;
    }
    void dfs(int begin, map<int,set<int>>& umap, set<int>& visited,vector<int>& res){
        for(auto i: umap[begin]){
            if(visited.find(i) == visited.end()){
                res.push_back(i);
                visited.insert(i);
                dfs(i,umap,visited,res);
            }
        }
    }
};
/*
    bài này ý tưởng sao nhỉ, nhìn đơn giản thế mà 
    xây dựng danh sách kề cho mỗi node, node nào danh sách kề chỉ có 1 đỉnh thì node đó 
    chính là đỉnh bắt đầu trong array 
*/