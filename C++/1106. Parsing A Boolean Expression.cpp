class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> opCode, operand;
        for (char c: expression) {
            switch (c) {
                case '(':
                case 'f':
                case 't':
                    operand.push(c);
                    break;
                case '!':
                case '|':
                case '&':
                    opCode.push(c);
                    break;
                case ')':
                    char opr = opCode.top();
                    opCode.pop();
                    bool res;
                    switch (opr) {
                        case '&':
                            res = true;
                            while (operand.top() != '(') {
                                res &= ((operand.top() == 'f') ? false : true);
                                operand.pop();
                            }
                        break;
                        case '|':
                            res = false;
                            while (operand.top() != '(') {
                                res |= ((operand.top() == 'f') ? false : true);
                                operand.pop();
                            }
                        break;
                        case '!':
                            res = ((operand.top() == 't') ? false : true);
                            operand.pop();
                        break;
                    }
                    operand.pop();
                    operand.push((res ? 't' : 'f'));
            }
        }
        return (operand.top() == 't');
    }
};
