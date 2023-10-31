class Solution {
public:
    vector<long long> distance(vector<int>& nums) 
    {
        int L = nums.size();
        vector<long long>res(L,0);
        unordered_map<int,vector<int>> m;
        // build vector of indexes
        for (int i = 0; i < L; i++) 
            m[nums[i]].push_back(i);
        // build res
        for (auto ite : m)
        {
            int num = ite.first;
            vector<int>& indexes = ite.second; // sorted array
            
            long long total_sum = 0;
            for (int index : indexes) 
                total_sum += index;
            
            long long left_sum = 0;
            int len = indexes.size();
            for (int i = 0; i < len; i++)
            {
                int index = indexes[i];
                long long right_sum = total_sum - left_sum - index;
                res[index] = (long long)index * i - left_sum + right_sum - index * (long long)(len - i - 1);
                left_sum += index;
            }
        }

        return res;    
    }
};