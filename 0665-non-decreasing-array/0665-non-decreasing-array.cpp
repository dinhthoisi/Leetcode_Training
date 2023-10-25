class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int L = nums.size();
        if(L == 1 || L == 2) return true; 
        int count = 0;
        int index = 0;
        if(nums[0] > nums[1]){     
            nums[0] = nums[1];
            for(int i = 1; i < L - 1; i++){
                if(nums[i] > nums[i+1])
                    return false;
            }
        }
        for(int i = 0; i < L - 1; i++){
            if(i >= 1 && nums[i] > nums[i+1]){
                count++;
                // modify nums[i]
                if(nums[i+1] >= nums[i-1])
                    nums[i] = nums[i+1];
                else
                    nums[i+1] = nums[i];
                index = i + 1;
                break;         
            }
        }
        if(count == 1){
            for(int i = index; i < L - 1; i++){
                if(nums[i] > nums[i+1]) 
                    return false;
            }
        }
        return true;
    }
};