#define loop(i, x) for (int i= 0; i < x; i++)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       if (magazine.length() < ransomNote.length()) return false;
       int arr[26];
       loop(i, 26) arr[i] = 0;
       loop(i, magazine.length()) arr[magazine[i]-'a']++;
       loop(i, ransomNote.length()) arr[ransomNote[i]-'a']--;
       loop(i, 26) if (arr[i] < 0) return false;
       return true;     
    }
};