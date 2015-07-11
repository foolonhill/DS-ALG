#include <stack>

class Solution {
public:
    bool isValid(string s) {
        
        if (s.length() % 2 != 0)
            return false;
        
        std::stack<char> st;
        
        for (unsigned i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
                cout << st.top() << endl;
            } else {
                if (st.empty())
                    return false;
                else {
                    char tmp = st.top();
                    switch(s[i]) {
                        case ')':
                            if (tmp == '(')
                                st.pop();
                            else
                                return false;
                            break;
                        case ']':
                            if (tmp == '[')
                                st.pop();
                            else
                                return false;
                            break;
                        case '}':
                            if (tmp == '{')
                                st.pop();
                            else
                                return false;
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        return st.empty();
    }
};
