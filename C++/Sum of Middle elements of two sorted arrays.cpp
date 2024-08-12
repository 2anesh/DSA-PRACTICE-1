class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        vector<int>result;
        for(int i=0;i<arr1.size();i++){
            result.push_back(arr1[i]);
        }
        for(int i=0;i<arr2.size();i++){
            result.push_back(arr2[i]);
        }
        sort(result.begin(),result.end());
        int start=0;
        int end=result.size()-1;
        int mid = (start + end)/2;
        int final_ans=0;
        for(int i=mid;i<mid+1;i++){
            final_ans +=(result[mid] + result[mid+1]);
        }
        return final_ans;
    }
};
