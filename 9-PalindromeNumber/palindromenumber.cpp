#include <limits.h>
class Solution {
public:
   static bool isPalindrome(int x) {
        int x1 = x;
        bool negative = false;
        if (x == INT_MIN)
            return false;
        if (x < 0) {
            return false;
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
        if( y == x1)
        return true;
        return false;
    }
};

int main() {
    int x =  Solution::isPalindrome(3);
}