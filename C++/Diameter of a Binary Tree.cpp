class Solution {
  public:
 int ans=INT_MIN;
     int dia(Node* root){
         if(!root)return 0;
      int d1=dia(root->left)+1,d2=dia(root->right)+1;
      
      if(d1+d2>ans)ans=d1+d2;
      return max(d1,d2);
         
     }
    int diameter(Node* root) {
        dia(root);
      return ans-2;
    }
};
