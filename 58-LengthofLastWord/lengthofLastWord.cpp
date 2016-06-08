class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool space = false;
        for (int i=0; i < s.length(); i++) { // look for the last space;
            if (s[i] == ' ') {
                space = true;   
            } else {
                if (space) {
                    count = 1;
                    space = false;
                } else {
                    count++;
                }
            }
        }
        return count;
    }
};