class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        final int m = matrix.length;
    final int n = matrix[0].length;
    int res = 0;
    for (int[] row : matrix)
      for (int i = 1; i < n; ++i)
        row[i] += row[i - 1];
    for (int baseCol = 0; baseCol < n; ++baseCol)
      for (int j = baseCol; j < n; ++j) {
        Map<Integer, Integer> prefixCount = new HashMap<>();
        prefixCount.put(0, 1);
        int sum = 0;
        for (int i = 0; i < m; ++i) {
          if (baseCol > 0)
            sum -= matrix[i][baseCol - 1];
          sum += matrix[i][j];
          res += prefixCount.getOrDefault(sum - target, 0);
          prefixCount.merge(sum, 1, Integer::sum);
        }
      }
    return res;
    }
}
