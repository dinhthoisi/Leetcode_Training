class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int res = 0;
        for(int i = n / 2 - 1; i >= 0; i--){
            int left = i*2 + 1, right = i*2 + 2;
            res += abs(cost[left]-cost[right]);
            cost[i] += max(cost[left],cost[right]);
        }
        return res;
    }
};