class Solution {
public:
    vector<string> generateParenthesis(int n) {
         vector<string> a;
        if (n >= 1)
        a = {"()"};
        int start = 0;
        int length = 1;
        if (n > 1) {
            for (int i = 1; i < n; i++) {
                int count = 0;
                for (int k = 0; k < length; length--) {
                    string abc ="("+ a[0] + ")";
                    a.push_back(abc);
                    count++;
                    string one = "()" + a[0];
                    string two = a[0] + "()";
                    if (one == two) {
                        a.push_back(one);
                        count++;
                    } else {
                          a.push_back(one);
                        a.push_back(two);
                        count += 2;
                    }
                    a.erase(a.begin());
                    
                }
                length = count;
            }
        }
        return a;
    }
};