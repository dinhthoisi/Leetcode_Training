class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int L = roads.size();
        // lưu mỗi đỉnh với số lượng neighbors -> map;
        map<int,int> m;
        for(int i = 0; i < L ;i++){
            m[roads[i][0]]++;
            m[roads[i][1]]++;
        }
        // Convert the map to a vector of pairs
        vector<pair<int, int>> v(m.begin(), m.end());
        // Sort the vector by comparing the second value of pairs
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
        );
        int i = n;
        vector<int> a(n);
        for(auto& pair: v){
            pair.second = i;
            a[pair.first] = pair.second;
            i--;
        }  
        long long importance = 0;
        for(int i = 0; i < L; i++){
            importance += a[roads[i][0]] + a[roads[i][1]];
        }
        
        return importance;
    }
};
//unordered_map<int,unordered_set<int>> m;
//int L = roads.size();
// build the map m 
//for(int i = 0; i < L; i++){
//    m[roads[i][0]].insert(roads[i][1]);
//    m[roads[i][1]].insert(roads[i][0]);
//}