class Solution {
public:
    string reverseParentheses(string s) {
        int L = s.size();
        stack<int> sta;
        int left,right;
        for(int i = 0; i < L; i++){
            if(s[i] == '('){
                sta.push(i);
            }
            else if(s[i] == ')'){
                left =sta.top();
                sta.pop();
                right = i;
                reverse(s.begin() + left,s.begin() + right);
            }
        }
        string res = "";
        for(int i = 0; i < L; i++){
            if(s[i] != '(' && s[i] != ')')
                res += s[i];
        }
        return res;
    }
    /*
    string reverse(string t){
        int L = t.size();
        int i = 0;
        int j = L - 1;
        while(i<=j){
            char te = t[i];
            t[i] = t[j];
            t[j] = te;
            i++;
            j--;
        }
        return t;
    }
    */
};