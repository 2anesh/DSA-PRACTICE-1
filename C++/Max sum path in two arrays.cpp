class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size() , n2 = arr2.size();
        vector<int> common;
        int prev_sum1 = 0 , prev_sum2 = 0;
        int ans = 0;
        int i = 0 , j = 0;
        while(i < n1 && j < n2){
            if(arr1[i] == arr2[j]){
                ans += arr1[i];
                ans = ans + max(prev_sum1 , prev_sum2);
                prev_sum1 = 0;
                prev_sum2 = 0;
                i++;
                j++;
            }
            else if(arr1[i] < arr2[j]){
                prev_sum1 += arr1[i];
                i++;
            }
            else{
                prev_sum2 += arr2[j];
                j++;
            }
        }
        while(i < n1){
            prev_sum1 += arr1[i];
            i++;
        }
        while(j < n2){
            prev_sum2 += arr2[j];
            j++;
        }
        ans += max(prev_sum1,prev_sum2);
        return ans;
    }
};
