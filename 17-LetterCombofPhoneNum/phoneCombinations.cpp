class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int total = 1;
        vector<string> elements;
        vector <string> nothing;
        for (int i = 0; i < digits.length(); i++) {
            if (digits[i] == '2') {
                elements.push_back("abc");
                total *=3;
            } else if (digits[i] == '3') {
                elements.push_back("def");
                total *=3;
            } else if (digits[i] == '4') {
                elements.push_back("ghi");
                total *=3;
            } else if (digits[i] == '5') {
                elements.push_back("jkl");
                total *=3;
            } else if (digits[i] == '6') {
                elements.push_back("mno");
                total *=3;
            } else if (digits[i] == '7') {
                elements.push_back("pqrs");
                total *= 4;
            } else if (digits[i] == '8') {
                elements.push_back("tuv");
                total *=3;
            } else if (digits[i] == '9') {
                elements.push_back("wxyz");
                total *=4;
            }
        }
        if (total == 1)
        return nothing;
        vector<string> perms;
        for (int i = 0; i < total; i++) {
            string entry = "";
            int f = 1;
            for (int k = elements.size()-1; k>=0; k--) {
                string temp = elements[k];
                int length = temp.length();
                entry = temp[(i/f)%length] + entry;
                f *= length;
            }
            perms.push_back(entry);
        }
        return perms;
    }
};