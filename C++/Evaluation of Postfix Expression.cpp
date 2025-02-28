class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        int n= arr.size();
        int i = 0;
        
        while(i<n){
            string x = arr[i];
            if(isdigit(x[0]) || (x[0] == '-' && x.size() > 1)){
                int num = stoi(x);
                st.push(num);
            }
            else{
               
                    int num2 = st.top();
                    st.pop();
                    int num1 = st.top();
                    st.pop();
                    int newNum ;
                    if(x == "*"){
                        newNum = num1*num2;
                    }
                    else if(x == "/"){
                        newNum = num1/num2;
                    }
                    else if(x == "-"){
                         newNum = num1-num2;
                    }
                    else if(x == "+"){
                         newNum = num1+num2;
                    }
                    st.push(newNum);
                }
            
            i++;
        }
        
        return st.top();
    }
};
