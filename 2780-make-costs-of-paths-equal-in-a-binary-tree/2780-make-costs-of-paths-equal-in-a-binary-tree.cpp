class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int result = 0;
        vector<int> dp(n,0);
        for(int i = n / 2 - 1; i >= 0; i--){
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            dp[i] = dp[left] + dp[right] + abs(cost[left] - cost[right]);
            cost[i] += max(cost[left],cost[right]);
        }
        return dp[0];
    }
};