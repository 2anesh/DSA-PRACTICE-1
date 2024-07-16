class Solution {
public:
    bool findPath(TreeNode* LCA, int target,string& path){
        if(LCA==NULL){
            return false;
        }
        if(LCA->val==target){
            return true;
        }
        path.push_back('L');
        if(findPath(LCA->left,target,path)){
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(findPath(LCA->right,target,path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootTosource="";
        string rootTodestination="";
        findPath(root,startValue,rootTosource);
        findPath(root,destValue,rootTodestination);
        int l=0;
        while(l<rootTosource.length() && 
        l<rootTodestination.length() && 
        rootTosource[l]==rootTodestination[l]){
            l++;
        }
        string result="";
        for(int i=0;i<rootTosource.length()-l;i++){
            result.push_back('U');
        }
        for(int i=l;i<rootTodestination.length();i++){
            result.push_back(rootTodestination[i]);
        }
        return result;
    }
};
