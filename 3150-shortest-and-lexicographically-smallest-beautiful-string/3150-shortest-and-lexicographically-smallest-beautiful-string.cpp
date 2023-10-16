class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";
        bool status = true;
        int L = s.size();
        for(int i = 0; i < L; i++){
            if(s[i] == '1'){
                int no_ones = 0;
                for(int j = i; j < L; j++){
                    if(s[j] == '1')
                        no_ones++;
                    if(no_ones == k && status == true){
                        res = s.substr(i,j-i+1);
                        status = false;
                    }
                    else if(no_ones == k && status == false){
                        string t = s.substr(i,j-i+1);
                        if(t.size() < res.size()) res = t;
                        else if(t.size() == res.size() && t<res) res = t;
                    }
                }
            }    
        }

        return res;
    }
};