class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int N = nums.size();
        vector<int> max_left(N,0);
        vector<int> min_right(N,0);
        max_left[0] = nums[0];
        min_right[N-1] = nums[N-1];

        for(int i = 1; i < N; i++)
            max_left[i] = max(max_left[i-1],nums[i]);

        for(int i = N - 2; i >= 0; i--)
            min_right[i] = min(min_right[i+1],nums[i]);

        for(int i = 0; i < N - 1; i++){
            if(max_left[i] <= min_right[i+1])
                return i + 1;
        }

        return 0;
    }
};
/*
    left: max 
    right: min 
    max < min
*/