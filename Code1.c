int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int n = matrixSize;
    int m = matrixColSize[0];
    int* ans = (int*)malloc(n * sizeof(int)); // Allocate maximum possible size
    int ansCount = 0;

    for (int i = 0; i < n; i++) {
        int rowMin = INT_MAX, rowMinCol = -1;
        for (int j = 0; j < m; j++) {
            if (rowMin > matrix[i][j]) {
                rowMin = matrix[i][j];
                rowMinCol = j;
            }
        }

        int colMax = INT_MIN;
        for (int k = 0; k < n; k++) {
            if (colMax < matrix[k][rowMinCol]) {
                colMax = matrix[k][rowMinCol];
            }
        }

        if (rowMin == colMax) {
            ans[ansCount++] = rowMin;
        }
    }

    *returnSize = ansCount;
    return ans;
}
