class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int lower = 0;
        int curr_length = 0;
        map<char, int> map;
        for (int i = 0; i < s.size(); i++) {
            if (map.count(s[i]) != 0) { //already exists.
                int last_pos = map[s[i]]; // we have this elements last pos.
                for (int j = lower; j < last_pos+1; j++) {
                    map.erase(s[j]);
                }
                lower = last_pos+1;
                map[s[i]]= i;
            } else {
                map[s[i]] = i;
                curr_length = i +1 - lower;
                if (curr_length > max_length)
                    max_length = curr_length;
            }
            
        }
        return max_length;
    }
};