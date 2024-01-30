class Solution {
public:
    bool isNum(string string2){
        return string2 != "+" && string2 != "-" && string2 != "*" && string2 != "/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<long long> stop;  
        for(int i=0;i<tokens.size();i++){
            if(isNum(tokens[i])){
                stop.push(stoll(tokens[i]));  
            }
            else{
                long long x=stop.top();
                stop.pop();
                long long y=stop.top();
                stop.pop();
                if (tokens[i] == "+"){
					stop.push(x + y);
				}
				else if (tokens[i] == "-"){
					stop.push(y - x);
				}
				else if (tokens[i] == "*"){
					stop.push(y * x);
				}
				else if (tokens[i] == "/"){
					stop.push( y/x );
				}                
            }
        }
        return stop.top();
    }
};
