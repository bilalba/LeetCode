#define loop(i,x) for (int i = 0; i < x; i++)
class Solution {
public:
    int firstUniqChar(string s) {
        int array[26];
        int length = s.length();
        loop(i, 26) array[i] = 0;
        loop(i, length) array[s[i] -'a']++;
        loop(i, length) if (array[s[i]-'a'] == 1) return i;
        return -1;
    
    }
};