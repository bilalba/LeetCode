class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 0)
            return false;
        if (num == INT_MIN)
            return false;
        if ((num|1431655765) > 1431655765)
            return false;
        if ((num-1 & num) == 0)
            return true;
        return false;
    }
};