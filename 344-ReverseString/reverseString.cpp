class Solution {
public:
    string reverseString(string s) {
        string h = "";
        for (int i = 0; i < s.size(); i++) {
            h = s[i] +h;
        }
        return h;
    }
};