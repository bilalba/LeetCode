class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = "";
        int length;
        if (!strs.empty())
            length = strs[0].length();
        else
          return str;
        bool flag = true;
        for (int k = 0; k < length && flag; k++ ) {
            char first = strs[0][k];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][k] != first) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                str += first;
        }
        return str;
    }
};