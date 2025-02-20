class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double>ans;
        vector<int>vec;
        vec.push_back(arr[0]);
        ans.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            
            int ele=arr[i];
            int idx=lower_bound(vec.begin(),vec.end(),ele)-vec.begin();
            if(idx==vec.size())
            vec.push_back(ele);
            else
            vec.insert(vec.begin()+idx,ele);
            if(vec.size()%2){
                ans.push_back(vec[vec.size()/2]);
            }
            else{
                int idx1=vec.size()/2-1;
                int idx2=vec.size()/2;
                double num=double(vec[idx1]+vec[idx2])/2;
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};
