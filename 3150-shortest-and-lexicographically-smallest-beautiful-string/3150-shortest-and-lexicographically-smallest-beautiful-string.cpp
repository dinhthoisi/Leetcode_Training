class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int L = s.size();
        // edge case
        if(k==1){
            for(int i = 0; i < L; i++){
                if(s[i] == '1') return "1";
            }
        }
        
        //prefix[i]: no of '1' from index 0->i
        vector<int>prefix(L,0);
        if(s[0] == '1') prefix[0] = 1;
        for(int i = 1; i < L; i++){ // O(N)
            if(s[i] == '1') prefix[i] = prefix[i-1] + 1;
            else prefix[i] = prefix[i-1];
        }
        string res = "";     
        int r = 0, l = 0; // với mỗi r tìm l sao cho (l,r) nhỏ nhất và no of '1' trong (l,r) <= k
                          // lúc đó subarray tương ứng cần tìm là (l-1,r)
        bool status = true;
        for(r = 1; r < L; r++){
            for(int l1 = l; l1 <= r ; l1++){
                int i = 0, j = 0;
                if(s[l1] == '1') i = 1;               
                if(l1 == 0){
                    if(prefix[r] - prefix[l1] + i < k) 
                        break;                                                   
                }
                else{
                    if(s[l1-1] == '1') j = 1;
                    if((prefix[r] - prefix[l1] + i < k) && (prefix[r] - prefix[l1 - 1] + j >= k)){
                        if(prefix[r] - prefix[l1-1] + j == k && status == true){
                            res = s.substr(l1-1,r-l1+2);
                            status = false;
                        }
                        else if(prefix[r] - prefix[l1-1] + j == k && status == false){
                            string t = s.substr(l1-1,r-l1+2);
                            if(t.size() < res.size()) res = t;
                            else if(t.size() == res.size() && t<res) res = t;
                            l = l1; 
                            break;
                        }
                    }         
                }     
            }
        }
        return res;
    }
};