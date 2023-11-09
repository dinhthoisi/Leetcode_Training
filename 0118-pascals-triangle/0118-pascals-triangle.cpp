class Solution {
public:
    void pascalTrian(int row, int noRows, vector<vector<int>>& r) {
        // base case
        if (row == noRows)
            return;
        
        // the (row+1) th row 
        vector<int> currRow (row + 1, 1);

        for (int j = 1; j < row; j++)
            currRow[j] = r[row - 1][j - 1] + r[row - 1][j];
        
        r.push_back(currRow);
        // recursion call
        pascalTrian(row + 1, noRows, r);
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r;
        pascalTrian(0, numRows, r);

        return r;
    }
};