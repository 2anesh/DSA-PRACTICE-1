class Solution {
  public:
    string minSum(vector<int> &arr) {
        
        sort(arr.begin(), arr.end()); 

        int l = arr.size(), rem = 0;
        string ans = "";
    
        for (int i = l - 1; i >= 0; i -= 2) {
            if (i - 1 >= 0) {
                rem += arr[i] + arr[i - 1];  
            } else {
                rem +=  arr[i];  
            }

            if (rem > 0) ans.push_back((rem % 10) + '0'); 
            
            rem /= 10; 
        }
    
        if (rem > 0) ans.push_back((rem % 10) + '0');
    
        reverse(ans.begin(), ans.end());
        
        return ans;
    }

};

