class Solution {
public:
vector<int> ans;
vector<int> postorder(Node* root) {
    nary(root);
    return ans;
}
void nary(Node* root){
    if(root==NULL)
        return;
    for(auto a:root->children)
        nary(a);
    ans.push_back(root->val);
 }
};
