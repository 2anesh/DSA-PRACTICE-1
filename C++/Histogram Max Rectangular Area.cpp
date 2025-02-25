class Solution {
  public:
  vector<int> nextSmaller(vector<int>&arr){
      stack<int>st;
      vector<int>vec(arr.size());
      for(int i=arr.size()-1;i>=0;i--){
          while(st.empty()==false && arr[st.top()]>=arr[i])
          st.pop();
          st.empty()?vec[i]=-1:vec[i]=st.top();
          st.push(i);
      }
      return vec;
  }
  vector<int> prevSmaller(vector<int>&arr){
      stack<int>st;
      vector<int>vec;
      for(int i=0;i<arr.size();i++){
          while(st.empty()==false && arr[st.top()]>=arr[i])
          st.pop();
          st.empty()?vec.push_back(-1):vec.push_back(st.top());
          st.push(i);
      }
      return vec;
  }
    int getMaxArea(vector<int> &arr) {
        vector<int>nxtSmall=nextSmaller(arr);
        vector<int>preSmall=prevSmaller(arr);
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int length=arr[i];
            if(nxtSmall[i]==-1)
            nxtSmall[i]=arr.size();
            int breadth=nxtSmall[i]-preSmall[i]-1;
            ans=max(ans,length*breadth);
        }
        return ans;
    }
};
