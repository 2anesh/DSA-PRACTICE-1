class Solution{
    
    // Function for finding maximum and value pair
    public static int[] game_with_number(int arr[], int n) {
        // Traverse the array from index 0 to n-2
        for (int i = 0; i < n - 1; i++) {
            // Perform bitwise OR operation between arr[i] and arr[i+1]
            arr[i] = arr[i] | arr[i + 1];
        }
        return arr;
    }
}
