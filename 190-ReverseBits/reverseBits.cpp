class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int o= 0;
        if (n == 0)
            return n;
        int i;
        for (i = 31; i >= 0; i--) {
            o += ((n&1) << i);
            n >>= 1;
            if (n == 0)
                break;
        }
        return o;
    }
};