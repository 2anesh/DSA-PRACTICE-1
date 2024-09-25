class Solution {
public:
    struct trie{
        vector<trie*>child;
        int score;
        trie(){
            child.resize(26);
            score=0;
        }
    };    
    void insert(trie* root, string &str){
        for(int i=0;i<str.length();i++){
            if(root->child[str[i]-97]==NULL){
                root->child[str[i]-97]=new trie();
            }
            root=root->child[str[i]-97];
            root->score++;
        }
    }    
    vector<int>res;
    void findscore(trie* root,string &str){
        trie* curr=root;
        int sc=0;
        for(int i=0;i<str.length();i++){
            curr=curr->child[str[i]-97];
            sc+=(curr->score);
        }
        res.push_back(sc);
    }
    vector<int> sumPrefixScores(vector<string>& words) {
       trie *root=new trie();
       for(auto x:words)insert(root,x);
       for(auto x:words)findscore(root,x);
       return res;
    }
};
