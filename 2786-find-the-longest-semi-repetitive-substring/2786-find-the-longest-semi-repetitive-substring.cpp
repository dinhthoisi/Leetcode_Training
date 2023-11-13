class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int res = 2;
        int L = s.size();
        if(L==1) return 1;

        for(int i = 0; i < L - 1; i++){
            for(int j = i + 2; j < L; j++){
                if(semiRepetitiveSubstringChecking(s.substr(i, j-i+1)) == true)
                    res = max(res,j-i+1);
            }
        }

        return res;
    }

    bool semiRepetitiveSubstringChecking(string s){
        int count = 0;
        int L = s.size();
        for(int i = 0; i < L - 1; i++){
            if(s[i] == s[i+1]){
                count++;
            }
        }
        if(count <= 1) return true;
        return false;
    }
};
/*
    2 con trỏ di chuyển như thế nào đây ??? 

    
*/