class Solution {
public:
    int strStr(string haystack, string needle) {
        int L = haystack.size(); // size of haystack
        int H = needle.size(); // size of needle 

        for(int i = 0; i < L - H + 1; i++){ // loop over haystack
            int count = 0; // count number of matched characters
            int index = 0; // index in needle
            for(int j = i; j < i + H; j++ ){
                if(haystack[j] == needle[index])
                    count++;
                else  
                    break; 
                index++;
            }
            if(count == H) return i;
        }
        return -1;
    }
};