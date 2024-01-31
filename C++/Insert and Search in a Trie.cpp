class Solution
{
    public:
        void insert(struct TrieNode *root, string key)
        {
             if(key.length()==0){
        root->isLeaf=true;
        return;
    }
    int index=key[0]-'a';
    struct TrieNode*child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }else{
        child=getNode();
        root->children[index]=child;
    }
    insert(child,key.substr(1));
        }
        bool search(struct TrieNode *root, string key) 
        {
    if(root==NULL){
        return false;
    }
    if(key.length()==0){
        return root->isLeaf;
    }
    int index=key[0]-'a';
    struct TrieNode*child=root->children[index];
    return search(child,key.substr(1));
        }
};
