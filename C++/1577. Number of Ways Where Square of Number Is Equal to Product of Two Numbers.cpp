class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) 
    {
       int type1 = 0;
       unordered_map<long long int,int>mp;
       for(int i = 0 ; i < nums1.size() ; i++) mp[1LL * nums1[i]*nums1[i]]++;
       for(int j = 0 ; j < nums2.size() ; j++)
       {
           for(int k = j+1 ; k < nums2.size() ; k++)
           {
               long long int product = (1LL*nums2[j]*nums2[k]);
               if(mp.find(product) != mp.end()) type1+=mp[product];
           }
       }    
      
       mp.clear();
       int type2 = 0;
       for(int i = 0 ; i < nums2.size() ; i++) mp[1LL * nums2[i]*nums2[i]]++;
       for(int j = 0 ; j < nums1.size() ; j++)
       {
           for(int k = (j+1) ; k < nums1.size() ; k++)
           {
               long long int product = (1LL * nums1[j]*nums1[k]);
               if(mp.find(product) != mp.end()) type2+=mp[product];
           }
       }
       return (type1 + type2);
    }
};
