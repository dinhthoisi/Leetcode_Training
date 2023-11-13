class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int res = 2, left = 0, right = 1, duplicate_index = 0;

        if(s.size() == 1) return 1;

        while(right < s.size()){
            if(s[right] == s[right-1]){
                // one duplicate is allowed. 
                if(duplicate_index != 0) 
                    left = duplicate_index;
                duplicate_index = right;
            }
            res = max(res,right-left+1);
            right++;
        }
        return res;
    }
};