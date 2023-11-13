class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int res = 1, left = 0, right = 1, last = 0;
        while(right < s.size()){
            if(s[right] == s[right-1]){
                // this is needed only for the 1st duplicate found, as we don't want to update the value
                // of left for the 1st duplicate. As one duplicate is allowed. 
                if(last) left = last;
                last = right;
            }
            res = max(res,right-left+1);
            right++;
        }
        return res;
    }
};