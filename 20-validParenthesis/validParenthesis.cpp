class Solution {
public:
    bool isValid(string s) {
        std::stack<int> s1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '('){
                s1.push(1);
            } else if (s[i] == '[') {
                s1.push(2);
            } else if (s[i] == '{') {
                s1.push(3);
            } else if (s1.empty()) {
                return false;
            }
            if (s[i] == ')') {
                 if (s1.top() != 1)
                    return false;
                    s1.pop();
            } else if (s[i] == ']') {
                if (s1.top() != 2)
                    return false;
                    s1.pop();
            } else if (s[i] == '}') {
                if (s1.top() != 3)
                    return false;
                s1.pop();
            }
            
        }
        if (s1.empty())
            return true;
        return false;
    }
};