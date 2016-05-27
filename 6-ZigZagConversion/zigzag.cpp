
#include <string>
using namespace std;

class Solution {
public:
    static string convert(string s, int numRows) {
        if  (numRows == 1)
        return s;
        string s1 = "";
        int gap_total = (numRows-1)*2;
        int gap = gap_total;
        int length = s.length();
        for (int i = 0; i < numRows; i++) {
            bool alternate = true;
            if (i == numRows -1)
                alternate = false;
            int t = i;
            while (t < length) {
                s1 += s[t];
                if (alternate)
                    t += gap;
                else
                    t+= (gap_total-gap);
                if (i != 0 && i != numRows-1)
                    alternate = !alternate;
            }
                gap -= 2;
        }
        return s1;
    }
};

int main() {
    Solution::convert("abcddfsd", 5);
}