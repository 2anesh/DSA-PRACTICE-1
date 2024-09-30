class CustomStack {
public:
    stack<int> st;
    int totalSize=0;
    CustomStack(int maxSize) {
        totalSize=maxSize;
    }    
    void push(int x) {        
        if(st.size()<totalSize){
            st.push(x);
        }
    }    
    int pop() {        
        if(!st.empty()){
              int i = st.top();
              st.pop();
              return i;
        }else{
            return -1;
        }
    }    
    int helper(int k ,int val){
if(st.empty()){
    return 1;
}
int valCureent = st.top();
st.pop();
int increement = helper(k,val);
if(increement<=k){
st.push(valCureent+val);
}else{
    st.push(valCureent);
}
return increement+1;
    }
    void increment(int k, int val) {
        helper(k,val);
    }
};
