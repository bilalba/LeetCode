class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        if (length == 0)
            digits.push_back(1);
        
        int point = length-1;
         while (digits[point] == 9 && point >= 0){
            digits[point] = 0;
            point--;
         }
        if (point >= 0) {
            digits[point]++;
            return digits;
        } else {
            digits.push_back(1);
            for (int i = length; i > 0; i--) {
                digits[i] = digits[i-1];
            }
            digits[0]= 1;
            return digits;
        }
    }
};