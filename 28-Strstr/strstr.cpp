class Solution {
public:
    int strStr(string haystack, string needle) {
        int haysize = haystack.length();
        int needlesize = needle.length();
        if (haysize < needlesize)
        return -1;
        if (haysize == 0 || needlesize == 0)
        return 0;
        for (int i = 0; i < haysize+1-needlesize; i++) {
            bool check = true;
            for (int k = 0; k < needlesize; k++) {
                if (haystack[i+k] != needle[k]) {
                    check = false;
                    break;
                }
            }
            if (check)
                return i;
            
        }
        return -1;
    }
};