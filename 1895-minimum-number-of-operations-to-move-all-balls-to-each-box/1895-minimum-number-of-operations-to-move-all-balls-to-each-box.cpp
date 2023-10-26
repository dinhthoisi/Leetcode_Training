class Solution {
public:
    vector<int> minOperations(string boxes) {
        int N = boxes.size();
        vector<int>leftcount(N,0);
        vector<int>rightcount(N,0);
        vector<int>leftcost(N,0);
        vector<int>rightcost(N,0);
        vector<int>tottalcost(N,0);

        for(int i = 1; i < N; i++){
            if(boxes[i-1] == '1') leftcount[i] = leftcount[i-1] + 1;
            else leftcount[i] = leftcount[i-1];
            leftcost[i] = leftcost[i-1] + leftcount[i];
        }
        //for(int i = 1; i < N; i++){
        //    leftcost[i] = leftcost[i-1] + leftcount[i];
        //}
        for(int i = N - 2; i >= 0; i--){
            if(boxes[i+1] == '1') rightcount[i] = rightcount[i+1] + 1;
            else rightcount[i] = rightcount[i+1];
            rightcost[i] = rightcost[i+1] + rightcount[i];
        }
        //for(int i = N - 2; i >= 0; i--){
        //    rightcost[i] = rightcost[i+1] + rightcount[i];
        //}
        for(int i = 0; i < N; i++){
            tottalcost[i] = leftcost[i] + rightcost[i];
        }

        return tottalcost;

    }
};