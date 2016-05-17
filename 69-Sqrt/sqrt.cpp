class Solution {
public:
    static int mySqrt(int x) {
         if (x < 0 ) {
            x *= -1;
        } else if (x == 1) {
            return 1;
        } else if ( x < 1) {
            return 0;
        } else {
            int y = 46340;
            int upper = 46340;
            int lower = 0;
            if (x >= 2147395600)
                return 46340;
            while (!(y*y <= x && (y+1)*(y+1) > x)) {
                if (y*y > x) { //y is greater than actual value. 
                        if (upper > y)
                            upper = y;
                        y /= 2;
                        if (lower > y)
                        y = (lower + upper)/2;
                } else if (y*y < x) {
                        if (lower < y) {
                            lower  = y;
                        }
                        y = (lower + upper)/2;
                }
            }
            return y;
            
        }
        return 0;
    }
};

int main() {
    Solution::mySqrt(999);
}