class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int row = i, rowMin = INT_MAX, rowMinCol = -1;
            for (int j = 0; j < m; j++) {
                if (rowMin > matrix[row][j]) {
                    rowMin = matrix[row][j];
                    rowMinCol = j;
                }
            }
            int col = rowMinCol, colMax = INT_MIN, colMaxRow = -1;
            for (int k = 0; k < n; k++) {
                if (colMax < matrix[k][col]) {
                    colMax = matrix[k][col];
                    colMaxRow = k;
                }
            }
            if (i == colMaxRow)
                ans.push_back(matrix[i][rowMinCol]);
        }
        return ans;
    }
};
