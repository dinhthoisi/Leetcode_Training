class Solution {
public:
    vector<long long> distance(vector<int>& nums) 
    {
        int L = nums.size();
        vector<long long>res(L);
        unordered_map<int,vector<int>> m;

        for (int i = 0; i < L; i++) 
            m[nums[i]].push_back(i);

        for (auto ite : m)
        {
            int num = ite.first;
            vector<int>& indexes = ite.second;
            //======================================================
            long long total_sum = 0;
            for (int index : indexes) 
                total_sum += index;
            
            long long pre_sum = 0;
            int len = indexes.size();
            for (int i = 0; i < len; i++)
            {
                int index = indexes[i];
                long long post_sum = total_sum - pre_sum - index;
                
                res[index] += ((long long)index * i);
                res[index] -= (pre_sum);
                res[index] -= (index * (long long)(len - i - 1));
                res[index] += post_sum;
                
                pre_sum += index;
            }
            //======================================================
        }
        return res;
        
        
    }
};