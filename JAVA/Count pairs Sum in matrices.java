class Solution {
    int countPairs(int mat1[][], int mat2[][], int n, int x) {
        int count=0;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i=0;i<mat1.length;i++){
            for(int j=0;j<mat1[0].length;j++){
                map.put(mat1[i][j], mat1[i][j]);
            }
        }
         for(int i=0;i<mat2.length;i++){
            for(int j=0;j<mat2[0].length;j++){
                int k =x-mat2[i][j];
                if(map.containsKey(k)){
                    count++;
                }
            
            }
        }
        return count;
    }
}
