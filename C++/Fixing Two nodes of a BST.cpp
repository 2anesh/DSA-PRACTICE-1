class Solution {
  public:
    void inorder(Node* root, vector<Node*> &v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
    void correctBST(Node* root) {
        vector<Node*> in;
        inorder(root,in);
        Node* a=NULL;
        Node* b=NULL;
        Node* c=NULL;
        bool s1=false,s2=false;
        for(int i=0;i<in.size()-1;i++){
            if(in[i]->data > in[i+1]->data && s1==false){
                a=in[i];
                b=in[i+1];
                s1=true;
                continue;
            }
            else if(in[i]->data > in[i+1]->data && s2==false ){
                c=in[i+1];
                s2=true;
                break;
            }
        }
        if(a && b && c){
            swap(a->data,c->data);
        }
        else{
            swap(a->data,b->data);
        }
    }
};
