#include <limits.h>
class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if (x == INT_MIN)
            return 0;
        if (x < 0) {
            negative = true;
            x *= -1;
        }
        int y = 0;
        int count = 0;
        while (x !=0 ) {
            count++;
            if (count == 10 && y > (INT_MAX/10)) {
                return 0; 
            }
                
            y *= 10;
            y += x%10;
            x = x/10;
        }
        if (negative)
        y *= -1;
        return y;
    }
};