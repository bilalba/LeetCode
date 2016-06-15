class Solution {
public:
    string longestPalindrome(string s) {
        // find three consecutive palindromic elements.
        // OR find two same elements.
        int length =  s.length();
        int max = 0;
        string r= "";
        if (length > 0) r = s[0], max =1;
        for (int i = 0; i < length-1; i++) {
            string a = "";
            int curr = 0;
            if (s[i] == s[i+1]) { // even number found.
                int j = 1;
                curr = 2;
                a =a +s[i] + s[i+1];
                // cout << ;
                while ((i-j >=0) && (i+1+j < length)) {
                    if (s[i-j] == s[i+1+j]) {
                        a =s[i-j] + a +s[i-j];
                        curr += 2;
                        j++;
                    } else {
                        break;
                    }
                }
                if (curr > max) max = curr, r= a;
                
            } 
            a = "";
            if (i < length-2)
                if (s[i] == s[i+2]) {
                    a = a + s[i] + s[i+1] +s[i];
                    int j = 1;
                    curr = 3;
                    while ((i-j >=0) && (i+2+j < length)) {
                        if (s[i-j] == s[i+2+j]) {
                            a =s[i-j] + a +s[i-j];
                            curr += 2;
                            j++;
                        } else {
                            break;
                        }
                    }
                    if (curr > max) max = curr, r= a;
                }
        }
        return r;
    }
};