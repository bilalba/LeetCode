class Solution {
public:
    int romanToInt(string s) {
        int a= 0;
        int last = 0;
        for (int i = 0; i < s.length(); i++) {
            
            int curr;
            if (s[i] == 'I') {
                curr = 1;
            } else if (s[i] == 'V') {
                curr = 5;
            } else if (s[i] == 'X') {
                curr = 10;
            } else if (s[i] == 'L') {
                curr = 50;
            } else if (s[i] == 'C') {
                curr = 100;
            } else if (s[i] == 'D') {
                curr = 500;
            } else if (s[i] == 'M') {
                curr = 1000;
            }
            if (last < curr && last != 0)
                curr =curr - last*2;
            last = curr;
            a += curr;
                
        }
        return a;
    }
};