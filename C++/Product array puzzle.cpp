class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        vector<int> v;
        int ans = 1;
        int count = 0;
        
        for(int i=0;i<arr.size();i++){
            if( arr[i] == 0){
                count++;
            }
        }
        
        for(int i=0;i<arr.size();i++){
            if( arr[i] != 0){
                ans = ans * arr[i];
            }
        }
        
        if( count == 0){
            for(int i=0;i<arr.size();i++){
                v.push_back(ans/arr[i]);
            }
        return v;
        }
        
        else if(count == 1){
            for(int i=0;i<arr.size();i++){
                if( arr[i] != 0){
                    v.push_back(0);
                }
                else{
                    v.push_back(ans);
                }
            }
            return v;
        }
        
        else{
            for(int i=0;i<arr.size();i++){
                v.push_back(0);
            }
            return v;
        }
    }
};

