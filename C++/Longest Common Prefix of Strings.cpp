class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        int mini = INT_MAX;
        string ans;
        bool flag = false;
        for(int i=0;i<arr.size();i++){
            int l = arr[i].length();
            mini = min(mini,l);
        }
        for(int i=0;i<mini;i++){
            char c = arr[0][i];
            for(int j=1;j<arr.size();j++){
                if(arr[j][i]!=c){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans+=c;
            }
            else{
                if(ans.length() == 0){
                   return "-1";
                }
                return ans;
            }
        }
        return ans;
    }
};
