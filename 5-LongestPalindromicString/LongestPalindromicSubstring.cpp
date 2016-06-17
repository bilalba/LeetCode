string findk(string s, int i, int j) { 

    int k = 1;
    int length = s.length();
    j += i -1;
    string a = "";
    for (int z =i; z <= j; z++)
        a += s[z];
    while (i-k >= 0 && (j +k < length)) {
        if (s[i-k] == s[j+k]){
             a = s[i-k] +a + s[i-k];k++;}
        else break;
    }
    return a;
}

class Solution {
public:
    string longestPalindrome(string s) {
        // find three consecutive palindromic elements.
        // OR find two same elements.
        int length =  s.length();
        int max = 0;
        string r= "";
        if (length > 0) r = s[0], max =1;
        int j = 1;
        for (int i = 0; i < length-1; i += j) {
            j =1;
            string a;
            int curr = 1;
            while (s[i] == s[i+j]) { // even number found.
                j++;
                if (i+j >= length) {
                    break;
                }   
            }
            
            if (j == 1) { // found no repeating elements.
                if (i+2 < length)
                    if (s[i] == s[i+2]) {
                        a =findk(s, i, 3);
                    }
            } else {
                a =findk(s, i, j);
                j--;
            }
            
            if (a.length() > max)
                max = a.length(), r = a;
        }
        return r;
    }
};