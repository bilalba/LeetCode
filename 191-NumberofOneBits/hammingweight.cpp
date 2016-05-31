class Solution {
public:
    int hammingWeight(uint32_t n) {
        int a =0;
        for (int i = 0; i < 32; i++) {
            if (n%2==1) {
                a++;
            }
            n =n >> 1;
        }
        
        return a;   
    }
};