class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int result = 0;
        for(int i = n / 2 - 1; i >= 0; i--){
            int left = i*2 + 1, right = i*2 + 2;
            result += abs(cost[left]-cost[right]); // update result
            cost[i] += max(cost[left],cost[right]); // update cost at node i
        }
        return result;
    }
};