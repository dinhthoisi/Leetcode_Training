class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefix_sum(N,0);
        prefix_sum[0] = nums[0];
        for(int i = 1; i < N; i++){
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }

        // find the pivot index 
        if((prefix_sum[N-1] - nums[0]) == 0) return 0;
        for(int i = 1; i < N - 1; i++){
            int left_sum = prefix_sum[i] - nums[i];
            int right_sum = prefix_sum[N-1] - prefix_sum[i];
            if(left_sum == right_sum)  
                return i;
        }
        if((prefix_sum[N-1] - nums[N-1]) == 0) return N-1;
        return -1;
    }
};