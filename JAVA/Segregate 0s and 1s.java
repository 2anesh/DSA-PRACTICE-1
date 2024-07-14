class Solution {
    void segregate0and1(int[] arr) {
        int i = 0; 
        int j = 0;
        while(j<arr.length){
            switch(arr[j]){
                case 0:{
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    i++;
                    j++;
                    break;
                }
                case 1:{
                    j++;
                    break;
                }
            }
        }
    }
}
