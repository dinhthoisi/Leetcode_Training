class Solution {
public:
    vector<int> minOperations(string boxes) {
        int L = boxes.size();
        vector<int> res(L,0);
        for(int i = 0; i < L ; i++){
            for(int j = 0; j < L; j++){
                if(i!=j){
                    if(boxes[j] == '1')
                        res[i] += abs(i-j);
                    if(boxes[i] == '1')
                        res[j] += abs(i-j);
                }
            }
        }
        for(int i = 0; i < L; i++)
            res[i] = res[i] / 2;
        return res;
    }
};