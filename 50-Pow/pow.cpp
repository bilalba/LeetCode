#include <limits.h>
class Solution {
public:
    double myPow(double x, int n) {
        double f = 1;
        if (x == 1)
            return 1;
        if (x == -1)
            return (n%2 == 1) ? -1 : 1;
        if (n < 0) {
            n= n * -1;
            if (n == INT_MIN)
                n = INT_MAX;
            for (int i = 0; i < n; i ++) {
                f /= (double)x;
                if (f == 0)
                return 0;
            
            }
            return f;
        }
            
        for (int i = 0; i < n; i ++) {
            f *= x;
            if (f == 0)
            return 0;
            
        }
            
        return f;
    }
};