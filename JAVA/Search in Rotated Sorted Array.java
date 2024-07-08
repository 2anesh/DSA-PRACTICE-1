class Solution {
    int search(int[] arr, int key) {
        int start = 0;
        int end = arr.length - 1;
        while( start <= end){
            int mid = (start + end)/2;
            if(arr[mid] == key) return mid; 
            if(arr[start] <= arr[mid])     
                if(arr[start] <= key && key <= arr[mid])    end = mid;  
                else    start = mid + 1;                                 
            else                           
                if(arr[mid] <= key && key <= arr[end])  start = mid;     
                else    end = mid-1;                                     
        }
        return -1;
    }
}
